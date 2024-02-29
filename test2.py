from collections import namedtuple
Point = namedtuple("Point", "x y")

O = 'Origin'
p = 0xfffffffffffffffffffffffffffffffffffffffffffffffffffffffefffffc2f
a = 0
b = 0x0000000000000000000000000000000000000000000000000000000000000007


def mod_invert(x, p=p):
    return pow(x, p-2, p)

def EccInv(P):
    if P == O:
        return P
    return Point(P.x, (-P.y)%p)

def EccAdd(P, Q):
    if P == O:
        result = Q
    elif Q == O:
        result = P
    elif Q == EccInv(P):
        result = O
    else:
        if P == Q:
            dydx = (3 * P.x**2 + a) * mod_invert(2 * P.y)
        else:
            dydx = (Q.y - P.y) * mod_invert(Q.x - P.x)
        x = (dydx**2 - P.x - Q.x) % p
        y = (dydx * (P.x - x) - P.y) % p
        result = Point(x, y)
    #print(result)
    return result


def mul(P, k):
    # x0=0
    N = P
    R = O

    while k:
        bit = k % 2
        k >>= 1
        if bit:
            R = EccAdd(R,N)
        N = EccAdd(N, N)
    return R

Gpoint = Point(55066263022277343669578718895168534326250603453777594175500187360389116729240, 32670510020758816978083085130507043184471273380659243275938904335757337482424)

#//print(EccAdd(Gpoint, Gpoint)) 

# //print(mul(Gpoint, mod_invert(0x75EA2AC47B5AB6798ED26A22346F3D5A313F7BA1F929BA9F99F5ABB045A9E9DA)))

privKey = 0x75EA2AC47B5AB6798ED26A22346F3D5A313F7BA1F929BA9F99F5ABB045A9E9DA
RandNum = 28695618543805844332113829720373285210420739438570883203839696518176414791234
gen2 = mul(Gpoint,privKey)
print(gen2)

#print("val above")
N = 0xfffffffffffffffffffffffffffffffebaaedce6af48a03bbfd25e8cd0364141
#print(mul(gen2, mod_invert(privKey, N)))

rg1 = mul(gen2, 50)
rg2 = mul(gen2, 50)
ah1 = mul(Gpoint, 5)

rg1ah1 = EccAdd(rg1, ah1)
ah2 = mul(Gpoint, 5)
rg2ah2 = EccAdd(rg2, ah2)
rgsum = EccAdd(rg1, rg2)
ahsum = EccAdd(ah1, ah2)

addedsum2 = EccAdd(rg1ah1, rg2ah2)
#//print(addedsum2)
addedsum = EccAdd(rgsum, ahsum)
#//print(addedsum)

rg = mul(gen2, 100)
ah = mul(Gpoint, 10)
added = EccAdd(rg, ah)

#//print(added)