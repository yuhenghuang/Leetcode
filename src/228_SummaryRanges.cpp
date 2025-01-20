#include <local_leetcode.hpp>

class Solution {
  private:
    void entry(vector<string>& res, int st, int ed) {
      if (st == ed) 
        res.push_back(to_string(st));
      else 
        res.push_back(to_string(st) + "->" + to_string(ed));
    }
  public:
    vector<string> summaryRanges(vector<int>& nums) {
      vector<string> res;
      int n = nums.size();
      if (n == 0) return res;

      int st, ed;
      st = ed = nums[0];
      for (int i = 1; i < n; ++i) {
        if (nums[i] == ed + 1)
          ++ed;
        else {
          entry(res, st, ed);
          st = ed = nums[i];
        }
      }

      entry(res, st, ed);

      return res;
    }
};


int main() {
  EXECS(Solution::summaryRanges);
  return 0;
}