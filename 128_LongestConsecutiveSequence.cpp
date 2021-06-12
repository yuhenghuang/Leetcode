#include <unordered_set>
#include "utils2.hpp"

class Solution {
  private:
    unordered_map<int, int> parent;

    int _find(int p) {
      auto iter = parent.find(p);
      if (iter->second != p) {
        iter->second = _find(p + 1);
      }

      return iter->second;
    }

    void _union(int p) {
      auto iter = parent.find(p + 1);
      if (iter != parent.end()) 
        parent[p] = _find(p + 1);
    }
 

  public:
    int longestConsecutiveTLE(vector<int>& nums) {
      // failed because of unbalanced UF

      for (int num : nums) 
        parent[num] = num;

      for (int num : nums)
        _union(num);

      int res = 0;

      for (int num : nums)
        res = max(res, _find(num) - num + 1);

      return res;
    }

    int longestConsecutive(vector<int>& nums) {
      unordered_set<int> s(nums.begin(), nums.end());

      int res = 0;

      for (int num : s) {
        if (s.count(num - 1) == 0) {
          int temp = 1;
          while (s.count(++num) > 0)
            ++temp;

          res = max(res, temp);
        }
      }

      return res;
    }
};


int main() {
  {
    UFUNC(Solution::longestConsecutive);
  }
  {
    UFUNC(Solution::longestConsecutiveTLE);
  }
  return 0;
}