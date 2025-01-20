#include <local_leetcode.hpp>

class Solution {
  public:
    string maximumNumber(string num, vector<int>& change) {
      string res = num;

      bool flag = false;
      for (char& c : res) {
        int d = c - '0';
        if (change[d] > d) {
          c = (char) (change[d] + '0');
          flag = true;
        }
        else if (flag && change[d] < d)
          break;
      }

      return res;
    }
};


int main() {
  EXECS(Solution::maximumNumber);
  return 0;
}