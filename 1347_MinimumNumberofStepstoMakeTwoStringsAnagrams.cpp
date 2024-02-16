#include <local_leetcode.hpp>

class Solution {
  private:
    array<int, 26> count_freq(const string& s) {
      array<int, 26> count;
      count.fill(0);

      for (char c : s)
        ++count[c - 'a'];

      return count;
    }

  public:
    int minSteps(string s, string t) {
      auto&& count1 = count_freq(s);
      auto&& count2 = count_freq(t);

      int positive = 0;
      int negative = 0;
      for (int i = 0; i < 26; ++i) {
        int diff = count1[i] - count2[i];

        if (diff > 0)
          positive += diff;
        else
          negative -= diff;
      }

      return min(positive, negative) + abs(positive - negative);
    }
};


int main() {
  EXECS(Solution::minSteps);
  return 0;
}