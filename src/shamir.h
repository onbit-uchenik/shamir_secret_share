//https://crypto.stackexchange.com/questions/10701/shamirs-secret-share-over-the-reals

#ifndef SHAMIR
#define SHAMIR

namespace shamir{
/*datatype to store the shares of each participant for each byte of secret.
  point is defined as
  stuct point {
    byte x,
    byte y,
  }
  this structure is used to store the x-coordinate and y-coordinate of polynomial.
}
*/
typedef std::vector<std::vector<GF256::point>> shares;

  class scheme{
    int n,k;
  public:
    scheme(int members,int threshold);
    shares* createShares(std::string secret);
    std::string getSecret(shares* Kshares);
  };
  /*
  this function should be called whenever the shamir library is required to used
  it calls the function gen_multipletable and srand for rand function.
  */
  void init();
}

#endif
