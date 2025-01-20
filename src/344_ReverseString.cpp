#include <local_leetcode.hpp>

class Solution {
  public:
    void reverseStringOld(vector<char>& s) {
      int i = 0, j = static_cast<int>(s.size()) - 1;
      while (i < j)
        swap(s[i++], s[j--]);
    }

    void reverseString(vector<char>& s) {
      reverse(s.begin(), s.end());
    }
};


int main() {
  EXECS(Solution::reverseStringOld);
  EXECS(Solution::reverseString);
  return 0;
}
