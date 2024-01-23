#include "../header/arithmetic.h"
#include "gmp.h"

finiteField initField(void) {
  finiteField new_field;
  mpz_init(new_field.field_len);
  mpz_init(new_field.point);

  return new_field;
}

void modinv(mpz_t a, mpz_t b, mpz_t gcd, mpz_t x, mpz_t y) {
  if (mpz_get_ui(b) == 0) {
    mpz_set(gcd, a);
    mpz_set_ui(x, 1);
    mpz_set_ui(y, 0);
  } else {
    mpz_t gcd_temp, x1, y1, temp;
    mpz_inits(gcd_temp, x1, y1, temp, NULL);

    mpz_mod(temp, a, b);
    modinv(b, temp, gcd, x1, y1);

    mpz_set(gcd, gcd_temp);
    mpz_set(x, y1);
    mpz_sub(temp, x1, y1);
    mpz_tdiv_q(temp, a, b);
    mpz_mul(temp, temp, y1);
    mpz_set(y, temp);

    mpz_clears(gcd_temp, x1, y1, temp, NULL);
  }
}

void subPoints(mpz_t pt1, const mpz_t pt2, const mpz_t field_len) {
  mpz_sub(pt1, (mpz_srcptr)pt1, (mpz_srcptr)pt2);

  mpz_mod(pt1, pt1, field_len);
}

void addPoints(mpz_t pt1, const mpz_t pt2, const mpz_t field_len) {
  mpz_add(pt1, (mpz_srcptr)pt1, (mpz_srcptr)pt2);

  mpz_mod(pt1, (mpz_srcptr)pt1, field_len);
}
