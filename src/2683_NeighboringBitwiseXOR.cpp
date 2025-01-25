#include <local_leetcode.hpp>

class Solution {
  public:
    bool doesValidArrayExist(vector<int>& derived) {
      int ones = count(derived.begin(), derived.end(), 1);
      return (ones ^ 1) & 1;
    }
};


int main() {
  EXECS(Solution::doesValidArrayExist);
  return 0;
}