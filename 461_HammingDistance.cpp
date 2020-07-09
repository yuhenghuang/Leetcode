#include <iostream>
using namespace std;

class Solution {
  public:
    int hammingDistance(int x, int y) {
      int res = 0;
      while (x>0 || y>0) {
        res += (x & 1) ^ (y & 1);
        x >>= 1;
        y >>= 1;
      }
      return res;
    }
};

int main() {
  Solution sol;
  cout << sol.hammingDistance(1, 4) << endl;
  return 0;
}