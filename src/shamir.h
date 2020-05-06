#ifndef SHAMIR
#define SHAMIR

namespace shamir{
  typedef std::vector<std::vector<GF256::point>> shares;

  class scheme{
    int n,k;
  public:
    scheme(int members,int threshold);
    shares* createShares(std::string secret);
    std::string getSecret(shares* Kshares);
  };

  void init();
}

#endif
