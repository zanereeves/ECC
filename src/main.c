#include "../header/arithmetic.h"
#include "gmp.h"
#include <assert.h>
#include <stdio.h>

int main() {

  mpz_t pcurve, scalar, c_val, N;
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

  mpz_set_str(
      pcurve,
      "fffffffffffffffffffffffffffffffffffffffffffffffffffffffefffffc2f", 16);

  mpz_init_set_str(
      scalar,
      "75EA2AC47B5AB6798ED26A22346F3D5A313F7BA1F929BA9F99F5ABB045A9E9DA", 16);

  mpz_init_set_str(c_val,
                   "75121778812004186636477969878696279828755133275959279706936"
                   "303845289286232491",
                   10);
  point gen = EccMult(&Gpoint, scalar, pcurve);
  mpz_invert(scalar, scalar, N);

  point invgen = EccMult(&gen, scalar, pcurve);
  // Test to see if we can succesfully invert a scalar
  assert(mpz_cmp(invgen.x, Gpoint.x) == 0);

  // testing scalars
  assert(mpz_cmp(gen.x, c_val) == 0);

  mpz_set_str(scalar,
              "7512177881200418663647796987869627982875513327595927970693630384"
              "5289286232491",
              10);
  // testing scalars
  point gen2 = EccMult(&Gpoint, scalar, pcurve);
  mpz_set_str(c_val,
              "8584636400820137081367262337451456290008530721076679585819230840"
              "8478887957311",
              10);
  // testing scalars
  assert(mpz_cmp(gen2.x, c_val) == 0);
  mpz_set(scalar, c_val);
  point gen3 = EccMult(&Gpoint, scalar, pcurve);
  mpz_set_str(c_val,
              "9178027858198522986506690462899832460214623527072350129118871294"
              "5107209395530",
              10);
  assert(mpz_cmp(c_val, gen3.x) == 0);

  return 0;
}
