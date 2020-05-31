#include <vector>
using namespace std;

class Solution {
  public:
    vector<int> countBits(int num) {
      vector<int> res(num+1);
      res[0] = 0;
      int jump = 1, idx = 1, temp = jump;
      for (int i=1; i<=num; ++i) {
        if (temp==0) {
          jump <<= 1;
          temp = jump;
        }
        res[i] = 1 + res[i-jump];
        --temp;
      }
      return res;
    }
};