#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "./src/GF(256).h"
#include "./src/shamir.h"

using namespace std;
using namespace GF256;
using namespace shamir;

int main(int argc,char** argv) {
  init();
  scheme scheme1(125,124);
  shares* scheme1_shares = scheme1.createShares("anubhav vats");
  for(int i=0;i<4;i++) {
      cout << "shares of pariticipant " << (i+1) << " => " << endl;
      for(auto val:(*scheme1_shares)[i]) {
          cout << val.x << " " << val.y << endl;
      }
      cout <<  "_____________________________________________________" << endl;

  }
  string secret = scheme1.getSecret(scheme1_shares);
  cout << secret << endl;
  return 0;
}
