#include <gmp.h>
#include <sodium.h>

typedef struct finiteField {
  mpz_t point;
  mpz_t field_len;
} finiteField;

finiteField initField(void);

void modinv(mpz_t b, mpz_t temp, mpz_t gcd_temp, mpz_t x1, mpz_t y1);
void subPoints(mpz_t pt1, const mpz_t pt2, const mpz_t field_len);
void addPoints(mpz_t pt1, const mpz_t pt2, const mpz_t field_len);
