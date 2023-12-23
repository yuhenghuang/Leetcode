#include <local_leetcode.hpp>

class Solution {
  public:
    vector<string> buildArray(vector<int>& target, int n) {
      vector<string> res;

      for (int i = 0, j = 1; i < target.size(); ++j) {
        res.push_back("Push");
        if (target[i] == j)
          ++i;
        else
          res.push_back("Pop");
      }

      return res;
    }
};


int main() {
  EXECS(Solution::buildArray);
  return 0;
}