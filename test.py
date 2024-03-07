O = 'origin'

def ec_inv(p1, N):
    if p1 == O:
        return p1
    
    return (p1[0], (-1 * p1[1]) % N)

def pointAdd(p1, p2, N):
    if O == p1:
        result = p2
    elif p2 == O:
        result = p1
    elif p2 == ec_inv(p1, N):
        result = O
    else:
        if p1[0] == p2[0]:
            return pointD(p1, N)
        x1, y1 = p1
        x2, y2 = p2

        lambd = ((y2 - y1)) * pow((x2 - x1), N-2, N) % N
        nx = ((lambd**2 % N) - (x2 % N) - (x1 % N)) % N
        ny = ((lambd*((x1 - nx) % N)) % N - y1) % N
        result = (nx, ny)

    return result

def pointD(p1, N):
    x1, y1 = p1
    lambd = (3*x1**2 % N) * (pow((2 * y1), N-2, N) % N) % N

    nx = (((lambd ** 2) % N) - ((2*x1) % N)) % N
    ny = (((lambd * (x1 - nx)) % N) - (y1 % N) ) % N
    return (nx, ny)

def DandA(p, scalar, N):
    scalar = bin(scalar)[2:]
    res = O
    temp = p
    for bit in scalar[::-1]:
        if bit == '1':
            res = pointAdd(res, temp, N)
        temp = pointD(temp, N)  
    return res


scal = 85846364008201370813672623374514562900085307210766795858192308408478887957311
Gx = 55066263022277343669578718895168534326250603453777594175500187360389116729240
Gy = 32670510020758816978083085130507043184471273380659243275938904335757337482424
GPoint = (Gx,Gy)

Pcurve = 115792089237316195423570985008687907853269984665640564039457584007908834671663
print(DandA(GPoint, scal, Pcurve))