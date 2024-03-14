#include "../header/arithmetic.h"
#include "gmp.h"
#include <assert.h>
#include <stdio.h>

int main() {

  mpz_t pcurve, randNum, c_val, N, a, primeOrder, r, msg, scalar;
  point Gpoint = initPoint();

  mpz_set_str(Gpoint.x,
              "5506626302227734366957871889516853432625060345377759417550018736"
              "0389116729240",
              10);
  mpz_set_str(Gpoint.y,
              "3267051002075881697808308513050704318447127338065924327593890433"
              "5757337482424",
              10);

  mpz_set_str(
      N, "fffffffffffffffffffffffffffffffebaaedce6af48a03bbfd25e8cd0364141",
      16);

  mpz_init(pcurve);
  mpz_init(a);

  mpz_set_str(
      pcurve,
      "fffffffffffffffffffffffffffffffffffffffffffffffffffffffefffffc2f", 16);

  mpz_init_set_str(randNum, "2869561854380", 10);

  mpz_init_set_str(primeOrder,
                   "11579208923731619542357098500868790785283756427907490438260"
                   "5163141518161494337",
                   10);

  mpz_init_set_str(
      scalar,
      "75EA2AC47B5AB6798ED26A22346F3D5A313F7BA1F929BA9F99F5ABB045A9E9DA", 16);

  mpz_set_ui(a, (unsigned long)0);
  point Q = EccMult(&Gpoint, scalar, pcurve, a);
  point rX = EccMult(&Gpoint, randNum, pcurve, a);
  mpz_init_set(r, rX.x);
  mpz_mod(r, r, primeOrder);

  mpz_init_set_str(msg, "101", 10);

  mpz_t s;
  mpz_init(s);

  sigGen(s, randNum, r, scalar, msg, pcurve, primeOrder);

  int outty = sigVerify(s, msg, r, Gpoint, Q, pcurve, primeOrder, a);

  assert(outty == 1);
  return 0;
}
