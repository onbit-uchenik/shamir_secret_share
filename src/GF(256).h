/*
  implementation of operations (divide, multiply, add, subtract, power ) in finite field GF(256).
  implementation of langrange interpolation in GF(256).
*/
#ifndef GF_256
#define GF_256


namespace GF256 {
   class byte {
   public:
     unsigned char num;
     byte();
     byte(unsigned char n);

     byte operator+(byte b);
     byte operator^(byte b);
     byte operator-(byte b);
     void operator=(int n);
     byte operator*(byte b);
     bool operator!=(byte b);
     byte operator~();
     byte operator/(byte b);

     void print();
   };


   typedef struct point{
       byte x;
       byte y;
   }point;

};
/*
  slow multiplication of bytes, a * b,Time Complexity : O(log a)
*/
GF256::byte slowMul(GF256::byte& a,GF256::byte& b);

std::ostream& operator<<(std::ostream& out, GF256::byte b);

bool operator<(const GF256::byte& lhs,const GF256::byte& rhs);
/*
  calculating a ^ b, time Complexity : O(log b)
*/
GF256::byte power(GF256::byte a,int b);

/*
  this function should be called so that a*b can be calculated O(1), also if this function is not
  called a*b will output always 0.
  the function precalculate exponents of  3 ^ rs where 0<=rs<=255, 3 is chosen becuase 3 is generator
  in field GF(256) when irreducible polynomial is :- x^8 + x^4 + x^3 + x + 1
  the function also precalculate logarithms to the base 3.
*/
void gen_multipletable();
/*
  lagrange interpolation algorithm.
  rather than calculating the complete ploynomial p(x) only value of p(0) is calculated as this is
  secret.
*/
unsigned char interpolate(std::vector<GF256::point>& share);
#endif
