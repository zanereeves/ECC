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

void Ed(point *p1, mpz_t field_len) {
  mpz_t lambda, temp, temp2, temp3, x;
  mpz_inits(lambda, temp, temp2, x, temp3, NULL);

  mpz_mul(lambda, p1->x, p1->x);
  mpz_mul_ui(lambda, lambda, 3U);
  mpz_add_ui(lambda, lambda, A_COEF_VAL);
  mpz_mod(lambda, lambda, field_len);

  mpz_mul_ui(temp, p1->y, 2);
  mpz_invert(temp, temp, field_len);

  mpz_mul(lambda, lambda, temp);
  mpz_mod(lambda, lambda, field_len);

  mpz_mul(x, lambda, lambda);
  mpz_mod(x, x, field_len);

  mpz_mul_ui(temp2, p1->x, 2U);
  mpz_sub(x, x, temp2);
  mpz_mod(x, x, field_len);

  mpz_sub(temp3, p1->x, x);
  mpz_mul(temp3, lambda, temp3);
  mpz_mod(temp3, temp3, field_len);

  mpz_sub(temp3, temp3, p1->y);
  mpz_mod(temp3, temp3, field_len);

  mpz_set(p1->x, x);
  mpz_set(p1->y, temp3);

  mpz_clears(lambda, temp, temp2, x, temp3, NULL);
}

void EAdd(point *P, point *Q, mpz_t field_len) {
  mpz_t lambda, mod_val, temp, nx, ny;
  mpz_init_set(temp, P->y);
  mpz_mul_si(temp, temp, (signed long)-1);
  mpz_mod(temp, temp, field_len);

  if (mpz_cmp_ui(P->x, MAGIC_NUM) == 0) {
    mpz_set(P->x, Q->x);
    mpz_set(P->y, Q->y);

  } else if (mpz_cmp_ui(Q->x, MAGIC_NUM) == 0) {

  } else if (mpz_cmp(Q->x, P->x) == 0 && mpz_cmp(temp, P->y) == 0) {
    mpz_set_ui(P->x, MAGIC_NUM);
    mpz_set_ui(P->y, MAGIC_NUM);
  } else {
    if (mpz_cmp(P->x, Q->x) == 0 && mpz_cmp(P->y, Q->y) == 0) {
      Ed(P, field_len);

    } else {
      // Sets up lambda (dydx val)
      mpz_init_set(lambda, Q->y);
      mpz_sub(lambda, lambda, P->y);
      mpz_mod(lambda, lambda, field_len);
      mpz_init_set(mod_val, Q->x);
      mpz_sub(mod_val, mod_val, P->x);
      mpz_invert(mod_val, mod_val, field_len);

      mpz_mul(lambda, lambda, mod_val);
      mpz_mod(lambda, lambda, field_len);

      // Sets up new x val
      mpz_init_set(nx, lambda);
      mpz_mul(nx, nx, nx);
      mpz_mod(nx, nx, field_len);
      mpz_sub(nx, nx, Q->x);
      mpz_sub(nx, nx, P->x);
      mpz_mod(nx, nx, field_len);
      // Sets up new y val
      mpz_init_set(ny, P->x);
      mpz_sub(ny, ny, nx);
      mpz_mod(ny, ny, field_len);
      mpz_mul(ny, ny, lambda);
      mpz_mod(ny, ny, field_len);
      mpz_sub(ny, ny, P->y);
      mpz_mod(ny, ny, field_len);

      mpz_set(P->x, nx);
      mpz_set(P->y, ny);

      mpz_clears(mod_val, lambda, nx, ny, NULL);
    }
  }

  mpz_clears(temp, NULL);
}

point EccMult(point *P, mpz_t scalar, mpz_t field_len) {

  point N = initPoint();
  point R = initPoint();

  mpz_set(N.x, P->x);
  mpz_set(N.y, P->y);

  mpz_set_ui(R.x, MAGIC_NUM);
  mpz_set_ui(R.y, MAGIC_NUM);
  unsigned long cap = 0;
  for (unsigned long i = 0; i < 256; i++) {
    if (mpz_tstbit(scalar, (mp_bitcnt_t)i)) {
      cap = i;
    }
  }

  for (unsigned long i = 0; i <= cap; i++) {
    if (mpz_tstbit(scalar, (mp_bitcnt_t)i)) {
      EAdd(&R, &N, field_len);
    }
    EAdd(&N, &N, field_len);
  }

  return R;
}

point PedersenCommit(point G, point H, mpz_t blinding_factor,
                     mpz_t hidden_value, mpz_t field_len) {
  point rG = EccMult(&G, blinding_factor, field_len);
  point aH = EccMult(&H, hidden_value, field_len);

  EAdd(&aH, &rG, field_len);
  return aH;
}
