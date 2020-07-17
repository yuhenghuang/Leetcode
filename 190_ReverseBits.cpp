#include <iostream>
using namespace std;

typedef unsigned int uint32_t;

class Solution {
  public:
    uint32_t reverseBits(uint32_t n) {
      uint32_t res = 0;
      for (int i=0; i<32; ++i) {
        res += ((n >> i) & 1) << (31 - i);
      }
      return res;
    }
};

int main() {
  Solution sol;
  cout << sol.reverseBits(4294967293) << endl;
  return 0;
}