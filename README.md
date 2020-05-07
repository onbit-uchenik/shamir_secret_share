# shamir_secret_share
C++ implementation of [Shamir Secret Scheme](https://medium.com/@apogiatzis/shamirs-secret-sharing-a-numeric-example-walkthrough-a59b288c34c4) over GF(256)

## Using Shamir Secret Share Library
 ```bash
  git clone https://github.com/onbitSyn/shamir_secret_share.git
  cd shamir_secret_share/
  ls -la
```
open your favourite editor vscode or atom
vscode
```bash
 code .
```
atom 
```bash
atom .
```
now create a new c++ file 
```c++
  #include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "./src/GF(256).h"
#include "./src/shamir.h"

using namespace std;
using namespace GF256;
using namespace shamir;

int main() {
  init(); //to initialise the library
  scheme scheme1(6,4);// a scheme is formed with 6 members out of which 4 will be used to reconstruct secret message
  shares* scheme1_shares = scheme1.createShares("Keep it Secret"); //6 shares are formed for secret "Keep it Secret".
  string secret = scheme1.getSecret(scheme1_shares); //secret is reconstructed from the shares
  cout << secret << endl;
  return 0;
  }
```
for more information see the [example](https://github.com/onbitSyn/shamir_secret_share/blob/master/example.cpp)
to compile code
```bash
g++ example.cpp ./src/shamir.o ./src/GF\(256\).o -o example
```
## How Shamir's Algorithm works
Consider a example in which a father wants to secretly divide his [Will](https://www.investopedia.com/articles/pf/08/what-is-a-will.asp) among 4 children and wants when 3 or more than 3 children wants to read it, then only it can be accessible.
Now, father uses shamir's algorithm to secretly divide the will into 4 pieces. 
Shamir algorithm make a random polynomial :-
```math
p(x) = a*x^2 + b*x + c
p(0) = c (represent will in integer)
p(1) = a+b+c
p(2) = 4*a + 2*b + c
p(3) = 9*a + 3*b + c
```
share of children 1 :- {1,p(1)}
share of children 2 :- {,p(2)}
share of children 3 :- {3,p(3)}
share of children 4 :- {4,p(4)}

## Implementation Details
Shamir's Secret Share Algorithm only works for the finite field, and this library performs all operations in [GF(256)](http://www.cs.utsa.edu/~wagner/laws/FFM.html).Each byte
of the secret is encoded as separate byte.
For reconstruction of the secret, Lagrange interpolation is used.

## License
Copyright © 2020 Anubhav Vats
Distributed under the Apache License 2.0
