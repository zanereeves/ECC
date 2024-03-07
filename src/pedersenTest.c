#include "../header/arithmetic.h"
#include "gmp.h"
#include <assert.h>

int main() {
  mpz_t pcurve, scalar, c_val;
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

  point Gpoint2 = EccMult(&Gpoint, scalar, pcurve);

  mpz_t r1, a1, r2, a2;
  mpz_inits(r1, a1, r2, a2, c_val, NULL);
  mpz_set_ui(r1, 50);
  mpz_set_ui(a1, 5);

  point pedP1 = PedersenCommit(Gpoint2, Gpoint, r1, a1, pcurve);

  mpz_set_str(c_val,
              "11043084939038699685475363203158763867535081129639300053955"
              "9411375734142049357",
              10);
  // testing commit value
  assert(mpz_cmp(pedP1.x, c_val) == 0);

  mpz_set_ui(r2, 50);
  mpz_set_ui(a2, 2);

  mpz_set_str(c_val,
              "6987939673246677070283132751324346153888208621006959210261994341"
              "5021891314746",
              10);

  point pedP2 = PedersenCommit(Gpoint2, Gpoint, r2, a2, pcurve);
  // testing commit value
  assert(mpz_cmp(pedP2.x, c_val) == 0);
  EAdd(&pedP1, &pedP2, pcurve);
  mpz_set_str(c_val,
              "5619364589038829500721827592507592769750400853926619349261477006"
              "9783543972077",
              10);
  // testing commit value
  assert(mpz_cmp(pedP1.x, c_val) == 0);

  mpz_t r1r2, a1a2;
  mpz_inits(r1r2, a1a2, NULL);
  mpz_set_ui(r1r2, 100);
  mpz_set_ui(a1a2, 7);

  point pedP3 = PedersenCommit(Gpoint2, Gpoint, r1r2, a1a2, pcurve);

  // testing for fulling homomorphic properties of PedersenCommitment scheme
  assert(mpz_cmp(pedP3.x, pedP1.x) == 0);
  return 0;
}
