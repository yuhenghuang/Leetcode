#include "utils2.hpp"

class Solution {
  public:
    int findLHS(vector<int>& nums) {
      unordered_map<int, int> m;
      for (int num : nums)
        ++m[num];

      int res = 0;
      for (auto p : m) {
        auto q = m.find(p.first+1);
        if (q!=m.end())
          res = max(res, p.second+q->second);
      }

      return res;
    }
};


int main() {
  UFUNC(Solution::findLHS);
  return 0;
}