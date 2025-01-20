#include <local_leetcode.hpp>

class Solution {
  public:
    vector<int> elementInNums(vector<int>& nums, vector<vector<int>>& queries) {
      int n = nums.size();

      vector<int> res;
      res.reserve(queries.size());

      for (auto& q : queries) {
        int t = q[0] % (n << 1);

        // start index
        int i = t < n ? t : 0;

        // length
        int l = t < n ? n - t : t - n;

        res.push_back(q[1] < l ? nums[i + q[1]] : -1);
      }

      return res;
    }

};


int main() {
  EXECS(Solution::elementInNums);
  return 0;
}