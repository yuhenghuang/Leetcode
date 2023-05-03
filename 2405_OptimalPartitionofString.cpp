#include <local_leetcode.hpp>

class Solution {
  public:
    int partitionString(string s) {
      int res = 1;
      
      int bits = 0;
      for (char c : s) {
        int b = 1 << (c - 'a');
        if (bits & b) {
          ++res;
          bits = 0;
        }
        bits |= b;
      }

      return res;
    }
};


int main() {
  EXECS(Solution::partitionString);
  return 0;
}