## Timeline
### This weeks timeline
I wrote up implementation code in python in two separate files because I wasn't managing to consolidate
both my C code output with my python code output and I wanted to make sure I understood the core logic.
Furthermore, I am currently wondering if it would be better to implement several cryptographic cryptography
schemes using just C as implementing via Nova would require a Risc instance for testing and I am currently
struggling with basic ECC math due to the awkwardness of GMP. Therefore, I am currently low confidence in my
ability to produce code that works without sufficient testing. I code possibly plan on outputting implementation
code in python before the end of term? As my turn around time on python is much faster than with C using gmp.



### Third meeting timeline

I wrote Pedersen commitment code and have what I believe to be a successful implementation.
The issue is on running through my EccMult code I believe there is a fundamental mess up in
how I am calculate addition within finite fields. This would explain why my code would
break when attempting to sum points over finite fields that aren't sufficiently large in length.
I rewrote EccMult code using a variety of algorithms that all should produce equal output; but with
my faulty Edouble and EAdd code something is fundamentally miss-calculating my finite field addition.


Additionally, I sifted through Nova's documentation and I have a decent grasp of the "plot" so to
speak of the project but I am somewhat confused as to how I would exactly implement such a large library.
Therefore, I started learning rust. I am currently about 1/4 of the way through an introductory textbook.

## Next week
I will start next week by writing a simple version of my code in python (so as to avoid
the confusing big integer arithmetic). Then I will rework, my C code to reflect the errors I detected
in python script. Additionally I will finish the introductory textbook for rust and start writing code for Nova.

## Week after
Finish Nova ???

## Resources and other Supplementary Materials
https://medium.com/@oleg.burundukov/pedersen-commitments-5726e14b65e
https://doc.rust-lang.org/book/
https://github.com/zanereeves/rust_tutorial

### Second meeting timeline
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




