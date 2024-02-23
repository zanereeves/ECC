#include "../header/arithmetic.h"
#include "gmp.h"
#include <stdio.h>

int main() {
  mpz_t N, test_key;
  finiteField field = initField();

  // Generates the correct value when printed. (Number of points in bitcoin
  // curve)
  //
  // NOTE THIS IS ALL ASSUMING BITCOIN sicp256k
  mpz_init_set_str(
      N, "FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEBAAEDCE6AF48A03BBFD25E8CD0364141",
      16);

  mpz_init_set_str(
      field.field_len,
      "FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEFFFFFC2F", 16);

  mpz_init_set_str(field.p.x,
                   "55066263022277343669578718895168534326250603453777594175500"
                   "187360389116729240",
                   10);

  mpz_init_set_str(field.p.y,
                   "32670510020758816978083085130507043184471273380659243275938"
                   "904335757337482424",
                   10);

  mpz_init_set_str(
      test_key,
      "A0DC65FFCA799873CBEA0AC274015B9526505DAAAED385155425F7337704883E", 16);

  gmp_printf("Num points in finite field: %Zd \n", N);
  gmp_printf("Prime value of finite field: %Zd \n", field.field_len);
  gmp_printf("Starting x value: %Zd \n", field.p.x);
  point test = EccMult(field.p, test_key, field.field_len);
  gmp_printf("Testing EccMult's x val in base 10: %Zd\n ... "
             "\n expected x val: C15E52947D2DB720D85BD02B0E4DE9E1B3",
             test.x);

  // NOTE THIS test.x VALUE IS PUBLIC KEY
  /*
  Edbltemp(field.p, field.field_len);
  gmp_printf("X-value after double over finite field: %Zd ... "
             "\n expected X-value: 5.659563192761507e+75\n",
             field.p.x);

  gmp_printf("Y-value after double over finite field: %Zd ... "
             "\n expected Y-value: 8.312157921655739e+76\n",
             field.p.y);
  */

  printf("\n\n\n");

  // At this point I first construct a c s.t. c = r*G + a*H by hand

  mpz_t blinding_factor, hidden_value;
  mpz_init_set_str(
      blinding_factor,
      "FFFFFFFFFFFFFFFFFFFFFFAFFFFFFFFEBAAEDCE6AF48A03BBFD25E8CD0364141", 16);

  mpz_init_set_str(hidden_value, "33", 10);

  point rGblinded = EccMult(test, blinding_factor, field.field_len);
  point aHhidden = EccMult(field.p, hidden_value, field.field_len);

  EAdd(aHhidden, rGblinded, field.field_len);

  gmp_printf("Output x-value of field: %Zd \n", aHhidden.x);

  finiteField field2 = initField();

  mpz_init_set_str(field2.p.x,
                   "55066263022277343669578718895168534326250603453777594175500"
                   "187360389116729240",
                   10);

  mpz_init_set_str(field2.p.y,
                   "32670510020758816978083085130507043184471273380659243275938"
                   "904335757337482424",
                   10);

  // Using this format I do the same thing but shorthand this process using a
  // function.
  point confirmation = PedersenCommit(test, field2.p, blinding_factor,
                                      hidden_value, field.field_len);

  gmp_printf("This should match with above print: %Zd \n", confirmation.x);

  // I now will show that this commitment scheme is homomorphic

  EAdd(aHhidden, confirmation, field.field_len);
  printf("\n\n\n");
  gmp_printf("Value of c + c = %Zd\n", aHhidden);

  point conf1 = PedersenCommit(test, field2.p, blinding_factor, hidden_value,
                               field.field_len);
  point conf2 = PedersenCommit(test, field2.p, blinding_factor, hidden_value,
                               field.field_len);

  EAdd(conf1, conf2, field.field_len);

  gmp_printf("confirmation of homomorphic properties... this should match "
             "above: %Zd \n",
             conf1.x);

  // Additional tests of homomorphic properties

  mpz_t b1, b2, h1, h2;
  mpz_init_set_str(b1, "510", 10);
  mpz_init_set_str(b2, "500", 10);
  mpz_init_set_str(h1, "100", 10);
  mpz_init_set_str(h2, "200", 10);

  point b1h1Point = PedersenCommit(test, field2.p, b1, h1, field.field_len);
  point b2h2Point = PedersenCommit(test, field2.p, b2, h2, field.field_len);

  EAdd(b1h1Point, b2h2Point, field.field_len);

  // Because this process should be Homomorphic, if we plug in
  // 300 for our hidden value, and summed blinding factors we shld get val
  // that is equal.
  mpz_t b1Plusb2, h1Plush2;
  mpz_inits(b1Plusb2, h1Plush2, NULL);
  mpz_add(b1Plusb2, b1, b2);
  mpz_add(h1Plush2, h1, h2);

  gmp_printf("\nb1Plusb2: %Zd\n", b1Plusb2);
  gmp_printf("\nh1Plush2: %Zd\n", h1Plush2);

  point homomorphicTest =
      PedersenCommit(test, field2.p, b1Plusb2, h1Plush2, field.field_len);

  printf("\n\n Additional Homomorphic test \n \n");

  gmp_printf("C + C = Cnew = %Zd\n", b1h1Point.x);
  gmp_printf("Cnew = (r1 + r2)*G + (h1 + h2)*H = %Zd\n", homomorphicTest.x);

  return 1;
}
