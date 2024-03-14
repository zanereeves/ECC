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

void EAdd(point *p1, point *p2, mpz_t field_len, mpz_t a);
void Ed(point *p1, mpz_t field_len, mpz_t a);
void Edbltemp(point p1, mpz_t field_len, mpz_t a);
point EccMult(point *P, mpz_t scalar, mpz_t field_len, mpz_t a);
point PedersenCommit(point G, point H, mpz_t blinding_factor,
                     mpz_t hidden_value, mpz_t field_len, mpz_t a);
int sigVerify(mpz_t s, mpz_t msg, mpz_t r, point G, point Q, mpz_t modField,
              mpz_t primeField, mpz_t a);
void sigGen(mpz_t dest, mpz_t randNum, mpz_t r, mpz_t privKey, mpz_t msg,
            mpz_t modField, mpz_t primeField);
