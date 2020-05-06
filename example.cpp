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
  init();//to initialise the library functions.Must be used to use the library.
  scheme scheme1(8,5); //creating a scheme with 8 shares and 5 threshold.
  shares* scheme1_shares = scheme1.createShares("its our team secret");
  //printing shares of all the participants...
  for(int i=0;i<8;i++) {
      cout << "shares of pariticipant " << (i+1) << " => " << endl;
      for(auto val:(*scheme1_shares)[i]) {
          cout << val.x << " " << val.y << endl;
      }
      cout <<  "_____________________________________________________" << endl;

  }
  //reconstructing the secret by giving  shares of all 8 members...
  string secret = scheme1.getSecret(scheme1_shares);
  cout << "construted secret using 8 shares -> " <<secret << endl;

  //reconstructing the secret by only shares of 5 members...
  shares* shares5 = new shares(5);
  for(int i=0;i<5;i++) {
    for(auto val:(*scheme1_shares)[i]) {
        (*shares5)[i].push_back(val);
    }
  }
  string newSecret = scheme1.getSecret(shares5);
  cout << "construted secret using 5 shares -> " << newSecret << endl;

  return 0;
}
