#include <local_leetcode.hpp>

class Solution {
  public:
    vector<int> findArray(vector<int>& pref) {
      vector<int> res;

      for (int i = 0, lagged_pre = 0; i < static_cast<int>(pref.size()); ++i)
        lagged_pre ^= res.emplace_back(lagged_pre ^ pref[i]);

      return res;
    }
};


int main() {
  EXECS(Solution::findArray);
  return 0;
}