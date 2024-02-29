#include "../header/arithmetic.h"
#include "gmp.h"
#include "inttypes.h"
#include <stdio.h>

point initPoint(void) {
  point p;

  mpz_init(p.x);
  mpz_init(p.y);
  return p;
}

const unsigned long MAGIC_NUM = 123456789101112;
const unsigned long A_COEF_VAL = 0;

void EAdd(point *p1, point *p2, mpz_t field_len) {
  mpz_t lambda, mod_val, temp, nx, ny;
  mpz_init_set(temp, p1->y);
  mpz_mul_si(temp, temp, (signed long)-1);
  mpz_mod(temp, temp, field_len);

  if (mpz_cmp_ui(p1->x, MAGIC_NUM) == 0) {
    mpz_set(p1->x, p2->x);
    mpz_set(p1->y, p2->y);

  } else if (mpz_cmp_ui(p2->x, MAGIC_NUM) == 0) {

  } else if (mpz_cmp(p2->x, p1->x) == 0 && mpz_cmp(temp, p2->y) == 0) {
    mpz_set_ui(p1->x, MAGIC_NUM);
    mpz_set_ui(p1->y, MAGIC_NUM);
  } else {
    if (mpz_cmp(p1->x, p2->x) == 0 && mpz_cmp(p1->y, p2->y) == 0) {
      Ed(p1, field_len);

    } else {
      // Sets up lambda (dydx val)
      mpz_init_set(lambda, p2->y);
      mpz_sub(lambda, lambda, p1->y);
      mpz_mod(lambda, lambda, field_len);
      mpz_init_set(mod_val, p2->x);
      mpz_sub(mod_val, mod_val, p1->x);
      mpz_invert(mod_val, mod_val, field_len);

      mpz_mul(lambda, lambda, mod_val);
      mpz_mod(lambda, lambda, field_len);

      // Sets up new x val
      mpz_init_set(nx, lambda);
      mpz_mul(nx, nx, nx);
      mpz_mod(nx, nx, field_len);
      mpz_sub(nx, nx, p2->x);
      mpz_sub(nx, nx, p1->x);
      mpz_mod(nx, nx, field_len);
      // Sets up new y val
      mpz_init_set(ny, p1->x);
      mpz_sub(ny, ny, nx);
      mpz_mod(ny, ny, field_len);
      mpz_mul(ny, ny, lambda);
      mpz_mod(ny, ny, field_len);
      mpz_sub(ny, ny, p1->y);
      mpz_mod(ny, ny, field_len);

      mpz_set(p1->x, nx);
      mpz_set(p1->y, ny);

      mpz_clears(mod_val, lambda, nx, ny, NULL);
    }
  }

  mpz_clears(temp, NULL);
}

void Ed(point *p1, mpz_t field_len) {
  mpz_t lambda, temp, temp2, x;
  mpz_inits(lambda, temp, temp2, x, NULL);

  mpz_mul(lambda, p1->x, p1->x);
  mpz_mul_ui(lambda, lambda, 3U);
  mpz_add_ui(lambda, lambda, 0U);
  mpz_mul_ui(temp, p1->y, 2);
  mpz_invert(temp, temp, field_len);

  mpz_mul(lambda, lambda, temp);
  mpz_mod(lambda, lambda, field_len);

  mpz_mul(x, lambda, lambda);
  mpz_mul_ui(temp2, p1->x, 2U);
  mpz_sub(x, x, temp2);
  mpz_mod(x, x, field_len);

  // gmp_printf("%Zd\n", x);
  mpz_sub(temp2, p1->x, temp);
  mpz_mul(temp2, lambda, temp2);
  mpz_sub(temp2, temp2, p1->y);
  mpz_mod(temp2, temp2, field_len);

  mpz_set(p1->x, x);
  mpz_set(p1->y, temp2);
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
    //  Ed(return_val, field_len);
    if (mpz_tstbit(scalar, (mp_bitcnt_t)cap)) {
      // EAdd(return_val, start, field_len);
    }
    cap -= 1;
  }

  return return_val;
}

point EccMult3(point start, mpz_t scalar, mpz_t field_len) {
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
    // Ed(return_val, field_len);

    if (mpz_tstbit(scalar, (mp_bitcnt_t)i)) {
      // EAdd(return_val, start, field_len);
    }
  }
  return return_val;
}

point EccMult(point start, mpz_t scalar, mpz_t field_len) {
  mpz_t mod_val;
  mpz_init(mod_val);

  point N = initPoint();
  point R = initPoint();

  mpz_set(N.x, start.x);
  mpz_set(N.y, start.y);

  mpz_set_ui(R.x, MAGIC_NUM);
  mpz_set_ui(R.y, MAGIC_NUM);

  while (mpz_sgn(scalar)) {
    mpz_mod_ui(mod_val, scalar, (unsigned long)2);
    mpz_fdiv_q_2exp(scalar, scalar, (unsigned long)1);

    if (mpz_sgn(mod_val)) {
      EAdd(&R, &N, field_len);
    }
    EAdd(&N, &N, field_len);
  }

  return R;
}

point PedersenCommit(point G, point H, mpz_t blinding_factor,
                     mpz_t hidden_value, mpz_t field_len) {
  point rG = EccMult(G, blinding_factor, field_len);
  point aH = EccMult(H, hidden_value, field_len);

  EAdd(&aH, &rG, field_len);
  return aH;
}
