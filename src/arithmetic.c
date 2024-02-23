#include "../header/arithmetic.h"
#include "gmp.h"
#include "inttypes.h"

point initPoint(void) {
  point p;

  mpz_init(p.x);
  mpz_init(p.y);
  return p;
}

finiteField initField(void) {
  finiteField new_field;

  new_field.p = initPoint();
  mpz_init(new_field.field_len);
  return new_field;
}

const unsigned long A_COEF_VAL = 0;

void EAdd(point p1, point p2, mpz_t field_len) {
  mpz_t lambda, mod_val, temp;
  mpz_inits(lambda, mod_val, temp, NULL);
  mpz_sub(lambda, p2.y, p1.y);

  mpz_sub(mod_val, p2.x, p2.y);
  mpz_invert(mod_val, mod_val, field_len);

  mpz_mul(lambda, lambda, mod_val);
  mpz_mod(lambda, lambda, field_len);

  mpz_mul(mod_val, lambda, lambda);
  mpz_sub(mod_val, mod_val, p1.x);
  mpz_sub(mod_val, mod_val, p2.x);
  mpz_mod(mod_val, mod_val, field_len);

  mpz_sub(temp, p1.x, mod_val);
  mpz_mul(temp, lambda, temp);
  mpz_sub(temp, temp, p1.y);
  mpz_mod(temp, temp, field_len);

  // mod_val holds the x value
  // temp holds the y value
  mpz_set(p1.x, mod_val);
  mpz_set(p1.y, temp);

  mpz_clears(lambda, mod_val, temp, NULL);
}

void Edbltemp(point p1, mpz_t field_len) { EAdd(p1, p1, field_len); }

void Ed(point p1, mpz_t field_len) {
  mpz_t lambda, temp, temp2, x;
  mpz_inits(lambda, temp, temp2, x, NULL);

  mpz_mul(lambda, p1.x, p1.x);
  mpz_mul_ui(lambda, lambda, 3U);
  mpz_add_ui(lambda, lambda, 0U);
  mpz_mul_ui(temp, p1.y, 2);
  mpz_invert(temp, temp, field_len);

  mpz_mul(lambda, lambda, temp);
  mpz_mod(lambda, lambda, field_len);

  mpz_mul(x, lambda, lambda);
  mpz_mul_ui(temp2, p1.x, 2U);
  mpz_sub(x, x, temp2);
  mpz_mod(x, x, field_len);

  // gmp_printf("%Zd\n", x);
  mpz_sub(temp2, p1.x, temp);
  mpz_mul(temp2, lambda, temp2);
  mpz_sub(temp2, temp2, p1.y);
  mpz_mod(temp2, temp2, field_len);

  mpz_set(p1.x, x);
  mpz_set(p1.y, temp2);
  mpz_clears(lambda, temp, temp2, x, NULL);
}

point EccMult2(point start, mpz_t scalar, mpz_t field_len) {
  point return_val = initPoint();

  mpz_init_set(return_val.x, start.x);
  mpz_init_set(return_val.y, start.y);
  int cap = 0;
  for (int i = 0; i < 256; i++) {
    if (mpz_tstbit(scalar, (mp_bitcnt_t)i)) {
      cap = i;
    }
  }

  cap -= 2;
  while (cap >= 0) {
    Ed(return_val, field_len);
    if (mpz_tstbit(scalar, (mp_bitcnt_t)cap)) {
      EAdd(return_val, start, field_len);
    }
    cap -= 1;
  }

  return return_val;
}

point EccMult(point start, mpz_t scalar, mpz_t field_len) {
  point return_val = initPoint();

  mpz_init_set(return_val.x, start.x);
  mpz_init_set(return_val.y, start.y);
  unsigned long cap = 0;
  for (unsigned long i = 0; i < 256; i++) {
    if (mpz_tstbit(scalar, (mp_bitcnt_t)i)) {
      cap = i;
    }
  }

  for (unsigned long i = 0; i <= cap; i++) {
    Ed(return_val, field_len);

    if (mpz_tstbit(scalar, (mp_bitcnt_t)i)) {
      EAdd(return_val, start, field_len);
    }
  }
  return return_val;
}

point PedersenCommit(point G, point H, mpz_t blinding_factor,
                     mpz_t hidden_value, mpz_t field_len) {
  point rG = EccMult(G, blinding_factor, field_len);
  point aH = EccMult(H, hidden_value, field_len);

  EAdd(aH, rG, field_len);
  return aH;
}
