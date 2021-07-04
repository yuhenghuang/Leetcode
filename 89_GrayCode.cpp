#include "utils2.hpp"

class Solution {
  public:
    vector<int> grayCode(int n) {
      vector<int> res;
      res.reserve(1 << n);

      res.push_back(0);
      for (int i = 0; i < n; ++i) 
        for (auto iter = res.rbegin(); iter != res.rend(); ++iter)
          res.push_back(*iter ^ (1 << i));

      return res;
    }
};


int main() {
  UFUNC(Solution::grayCode);
  return 0;
}