#include <local_leetcode.hpp>

class Solution {
  public:
    string mergeAlternately(string word1, string word2) {
      string res;
      auto i = word1.begin();
      auto j = word2.begin();

      for (; i != word1.end() && j != word2.end(); (void) ++i, (void) ++j) {
        res.push_back(*i);
        res.push_back(*j);
      }

      copy(i, word1.end(), back_inserter(res));
      copy(j, word2.end(), back_inserter(res));

      return res;
    }
};


int main() {
  EXECS(Solution::mergeAlternately);
  return 0;
}