#include "../header/arithmetic.h"
#include "gmp.h"

int main() {
  mpz_t test;
  mpz_init_set_str(test, "21", 10);

  gmp_printf("Value of test1: %Zd \n", test);

  mpz_t test2;
  mpz_init_set_str(test2, "10", 10);
  mpz_t fieldlen;
  mpz_init_set_str(fieldlen, "103", 10);
  gmp_printf("Value of fieldlen: %Zd\n", fieldlen);
  subPoints(test, test2, fieldlen);
  gmp_printf("Value of div test: %Zd \n", test);
  gmp_printf("Value of div test: %Zd \n", fieldlen);
  mpz_t gcd, x, y;
  mpz_inits(gcd, x, y, NULL);
  mpz_set_ui(test, 10);
  mpz_set_ui(fieldlen, 13);
  modinv(test, fieldlen, gcd, x, y);

  gmp_printf("Value of div test: %Zd \n", x);

  return 1;
}
