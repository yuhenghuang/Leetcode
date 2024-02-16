#include <local_leetcode.hpp>

class Solution {
  public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
      int freq[201] = {0};

      vector<vector<int>> res;

      for (int num : nums) {
        int f = freq[num]++;

        if (res.size() == f)
          res.emplace_back().push_back(num);
        else
          res[f].push_back(num);
      }

      return res;
    }
};


int main() {
  EXECS(Solution::findMatrix);
  return 0;
}