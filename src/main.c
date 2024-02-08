#include "../header/arithmetic.h"
#include "gmp.h"

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

  Edbltemp(field.p, field.field_len);
  gmp_printf("X-value after double over finite field: %Zd ... "
             "\n expected X-value: 5.659563192761507e+75\n",
             field.p.x);

  gmp_printf("Y-value after double over finite field: %Zd ... "
             "\n expected Y-value: 8.312157921655739e+76\n",
             field.p.y);

  printf("\n\n\n");

  // BN254 CURVE
  mpz_t test_key2;
  mpz_init_set_str(test_key2, "1", 10);
  finiteField bnfield = initField();
  printf("**** BN254 FIELD ****\n");
  mpz_init_set_str(
      bnfield.field_len,
      "40000000000000000000000000000000224698fc094cf91b992d30ed00000001", 16);
  mpz_init_set_str(
      bnfield.p.x,
      "40000000000000000000000000000000224698fc094cf91b992d30ed00000000", 16);
  mpz_init_set_str(bnfield.p.y, "1", 16);

  point test2 = EccMult(bnfield.p, test_key2, bnfield.field_len);

  gmp_printf("Testing EccMult's x val in base 10: %Zd\n ... "
             "\n expected ....",
             test2.x);

  return 1;
}
