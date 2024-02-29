#include "../header/arithmetic.h"
#include "gmp.h"
#include <stdio.h>

int main() {

  mpz_t pcurve, scalar;
  point Gpoint = initPoint();

  mpz_set_str(Gpoint.x,
              "5506626302227734366957871889516853432625060345377759417550018736"
              "0389116729240",
              10);
  mpz_set_str(Gpoint.y,
              "3267051002075881697808308513050704318447127338065924327593890433"
              "5757337482424",
              10);
  mpz_init(pcurve);

  mpz_set_str(
      pcurve,
      "fffffffffffffffffffffffffffffffffffffffffffffffffffffffefffffc2f", 16);

  mpz_init_set_str(
      scalar,
      "75EA2AC47B5AB6798ED26A22346F3D5A313F7BA1F929BA9F99F5ABB045A9E9DA", 16);
  gmp_printf("Scalar val: %Zd\n", scalar);

  // EAdd(Gpoint, Gpoint, pcurve); outputs appropriate Value
  point gen = EccMult(Gpoint, scalar, pcurve);
  gmp_printf("Pcurve val: %Zd\n", pcurve);
  gmp_printf("Value of mult: %Zd\n", gen.x);
  return 1;
}
