## Timeline
### This week
I completed an secp implementation that is reasonably effective. I have obtained a
more rote understanding of Elliptic Curves and I did some research on Pedersen commitments.
I am currently bouncing between either implementing BN254 curves because it sounds like fun
or continuing on the Pedersen commitment path.

Materials used: An Introduction to Mathematical Cryptography by J. Hoffstein and et al.
Elliptic Curves, Number Theory, and Cryptography by K. H. Rosen.
Abstract Algebra, Theory and Applications by Thomas W. Judson.

https://medium.com/coinmonks/zero-knowledge-proofs-um-what-a092f0ee9f28

Pedersen commitments use two generators over a finite field group (which we will call M and N)
where the discrete logarithm problem is considered computationally infeasible and generates a
proof of commitment to a value that is computationally cheap to prove and hiding so that an
outside observer would have difficulty discovering a value r known as the blinding factor such
that they could independently discover the committed value. Since we need to use generators
over a finite field group we’ll use elliptic curve cryptography to provide our needed generators M
and N.

## Next week
Work on implementing Pedersen commitments and read up on the theory.
Some resources:
https://medium.com/@oleg.burundukov/pedersen-commitments-5726e14b65e

A popular choice of curve for Pedersen Commitments is curve25519, I need to look into
exactly what makes this curve so desirable.

## Week after
Start working on Nova proof model.
