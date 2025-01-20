#include <local_leetcode.hpp>

class Solution {
  public:
    bool makeEqual(vector<string>& words) {
      const int n = words.size();

      int count[26] = {0};

      for (auto& word : words)
        for (char c : word)
          ++count[c - 'a'];

      for (int i = 0; i < 26; ++i)
        if (count[i] % n)
          return false;

      return true;
    }
};


int main() {
  EXECS(Solution::makeEqual);
  return 0;
}