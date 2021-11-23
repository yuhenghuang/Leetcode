#include "utils3.hpp"

class Solution {
  private:
    int nC2(int n) {
      return n * (n - 1) / 2;
    }

  public:
    int tupleSameProduct(vector<int>& nums) {
      unordered_map<int, int> m;
      for (int i = 0; i < nums.size(); ++i)
        for (int j = i + 1; j < nums.size(); ++j)
          ++m[nums[i] * nums[j]];

      int res = 0;
      for (auto& p : m)
        res += 8 * nC2(p.second);

      return res;
    }
};


int main() {
  UFUNCS(Solution::tupleSameProduct);
  return 0;
}