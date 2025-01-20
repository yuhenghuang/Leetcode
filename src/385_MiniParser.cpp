#include <local_leetcode.hpp>

class Solution {
  public:
    NestedInteger deserialize(string s) {
      return ll::universal_parser<NestedInteger>()(s);
    }
};


int main() {
  EXECS(Solution::deserialize);
  return 0;
}