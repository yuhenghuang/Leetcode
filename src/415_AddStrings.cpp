#include "utils3.hpp"

class Solution {
  public:
    string addStrings(string num1, string num2) {
      int rem = 0;
      string res;

      while (rem > 0 || !num1.empty() || !num2.empty()) {
        int sum = rem;
        if (!num1.empty()) {
          sum += num1.back() - '0';
          num1.pop_back();
        }

        if (!num2.empty()) {
          sum += num2.back() - '0';
          num2.pop_back();
        }

        rem = sum / 10;
        sum = sum < 10 ? sum : sum - 10;
        
        res.push_back('0' + sum);
      }

      reverse(res.begin(), res.end());
      return res;
    }
};


int main() {
  UFUNCS(Solution::addStrings);
  return 0;
}