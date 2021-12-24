#include <local_leetcode.hpp>

class Solution {
  public:
    string addSpaces(string s, vector<int>& spaces) {
      string res;
      res.reserve(s.size() + spaces.size());

      int j = 0;
      for (int i = 0; i < s.size(); ++i) {
        if (j < spaces.size() && i == spaces[j]) {
          res.push_back(' ');
          ++j;
        }

        res.push_back(s[i]);
      }

      return res;
    }
};


int main() {
  EXECS(Solution::addSpaces);
  return 0;
}