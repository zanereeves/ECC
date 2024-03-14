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



privKey = 0x75EA2AC47B5AB6798ED26A22346F3D5A313F7BA1F929BA9F99F5ABB045A9E9DA
RandNum = 2869561854380
gen2 = mul(Gpoint,privKey)


(x1, y1) = mul(Gpoint, RandNum)
x1 = x1 % p

primeOrder = 115792089237316195423570985008687907852837564279074904382605163141518161494337
r = x1 % primeOrder
msg = 101

s = (mod_invert(RandNum, primeOrder) * (msg + (privKey * r))) % primeOrder
w = mod_invert(s, primeOrder)
u1 = (msg * w) % primeOrder
u2 = (r * w) % primeOrder
(x2, y2) = EccAdd(mul(Gpoint, u1), mul(gen2, u2))


print(x2 % primeOrder == r)
