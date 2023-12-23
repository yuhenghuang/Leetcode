#include <local_leetcode.hpp>

class Solution {
  public:
    string largestGoodInteger(string num) {
      char res = '/';

      for (int i = 1; i + 1 < num.size(); ++i)
        if (num[i-1] == num[i] and num[i] == num[i+1] and num[i] > res)
          res = num[i];

      return res >= '0' ? string(3, res) : string();
    }
};


int main() {
  EXECS(Solution::largestGoodInteger);
  return 0;
}