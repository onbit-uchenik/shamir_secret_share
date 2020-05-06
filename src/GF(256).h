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

     byte slowMul(byte& a,byte& b);
     void print();
   };

   typedef struct point{
       byte x;
       byte y;
   }point;

};

std::ostream& operator<<(std::ostream& out, GF256::byte b);

bool operator<(const GF256::byte& lhs,const GF256::byte& rhs);
GF256::byte power(GF256::byte a,int b);

void gen_multipletable();

unsigned char interpolate(std::vector<GF256::point>& share);
#endif
