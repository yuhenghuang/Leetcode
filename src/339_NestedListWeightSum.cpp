#include <local_leetcode.hpp>


class Solution {
  private:
    int dfs(const vector<NestedInteger>& nestedList, int depth) {
      int sum = 0;
      for (const NestedInteger& ni : nestedList)
        sum += ni.isInteger() ? ni.getInteger() * depth : dfs(ni.getList(), depth + 1);

      return sum;
    }

  public:
    int depthSum(vector<NestedInteger>& nestedList) {
      return dfs(nestedList, 1);
    }
};


int main() {
  EXECS(Solution::depthSum);
  return 0;
}