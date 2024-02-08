#include <gmp.h>
#include <sodium.h>

typedef struct point {
  mpz_t x;
  mpz_t y;
} point;

typedef struct finiteField {
  point p;
  mpz_t field_len;
} finiteField;

finiteField initField(void);
point initPoint(void);

void EAdd(point p1, point p2, mpz_t field_len);
void Ed(point p1, mpz_t field_len);
void Edbltemp(point p1, mpz_t field_len);
point EccMult(point start, mpz_t scalar, mpz_t field_len);
