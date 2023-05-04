#include <local_leetcode.hpp>

class Solution {
  public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
      unordered_set<int> s1(nums1.begin(), nums1.end()), s2(nums2.begin(), nums2.end());

      vector<vector<int>> res(2);

      for (int num : s1)
        if (s2.count(num) == 0)
          res[0].push_back(num);

      for (int num : s2)
        if (s1.count(num) == 0)
          res[1].push_back(num);

      return res;
    }
};


int main() {
  EXECS(Solution::findDifference);
  return 0;
}