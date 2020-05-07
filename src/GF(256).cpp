/* Learn GF(256) from here http://www.cs.utsa.edu/~wagner/laws/FFM.html
   copyright law :- tps://law.stackexchange.com/questions/24517/when-is-copyright-infringement-committed
   https://www.youtube.com/watch?v=QD5-pMQfxSY&feature=youtu.be
*/


#include<iostream>
#include<vector>
#include "GF(256).h"

using namespace std;
using namespace GF256;





byte exponents[256];
byte logs[256];

ostream& operator<<(ostream& out, byte b){
    out << (int)b.num;
    return out;
}

byte::byte(unsigned char n) {
    num = n;
}

byte::byte() {
    num = 0;
}

byte byte::operator+(byte b) {
    return ( (*this) ^ b);
}

byte byte::operator-(byte b) {
    return ((*this) ^ b);
}

byte byte::operator^(byte b) {
    return num ^ (b.num);
}

void byte::operator=(int n) {
    num = n;
}

byte byte::operator*(byte b) {
    int t=0;
    if(num == 0 || b.num == 0) return 0;
    t  = logs[num].num + logs[b.num].num;
    if(t> 255) t = t-255;
    return exponents[t];
}

bool byte::operator!=(byte b) {
    return num != b.num;
}

byte byte::operator~(){
    unsigned char y = logs[num].num,x;
    x = 255 - y;
    return exponents[x];
}

byte byte::operator/(byte b) {
    byte c  = ~b;
    return (*this) * c;
}

byte slowMul(byte& a,byte& b) {
    unsigned int aa = a.num, bb = b.num, r=0, t;
    while(aa != 0) {
      if((aa & 1) != 0) {
        r = (r ^ bb);
      }
      t = (bb &  128);
      bb = (bb << 1);
      if(t != 0) {
        bb  = bb ^ 283;
      }
      aa = aa >> 1;
    }
    byte ans  = r;
    return ans;
}

void byte::print() {
    for(int i=0;i<256;i++) {
        printf("%x\t",exponents[i].num);
    }
    cout << endl;
    cout << "---------------------------------------------------------------------------" << endl;
    for(int i=1;i<256;i++) {
        printf("%x\t",logs[i].num);
    }
}

//overlaoded operator< for use of set functions;
bool operator<(const byte& lhs,const byte& rhs) {
  return lhs.num < rhs.num;
}

/*Recursive power function to calculate (a^b) % p
 *return: (a^b) in GF(256 )
 *argument: a and b */
byte power(byte a,int b) {
	if(b == 0) return 1;
	else{
		byte ans = power(a,b/2);
		if(b%2 != 0) return (ans * (ans* a));
		else return (ans * ans);
	}
}



void gen_multipletable() {
  byte generator = 3;
  exponents[0] = 1;;
  for(int i=1;i<256;i++) {
      exponents[i] = slowMul(generator,exponents[i-1]);
  }
  for(int i=0;i<256;i++) {
      logs[exponents[i].num] = i;
  }
  logs[1] = 0;
}

/*interpolation using the langrange interpolation*/
unsigned char interpolate(vector<point>& share) {
    byte secret = 0;
    int n = share.size();

    for(int i=0;i<n;i++) {
        byte term = 1;

        for(int j=0;j<n;j++) {
            if(i == j) continue;
            term = term * (share[j].x / (share[j].x - share[i].x));
        }
        term = term * share[i].y;
        secret = secret + term;
    }
    return secret.num;
}
