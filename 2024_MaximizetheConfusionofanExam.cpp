#include <local_leetcode.hpp>

class Solution {
  private:
    int impl(const string& s, int k, char t) {
      int res = 0;
      int j = 0;
      for (int i = 0; i < s.size(); ++i) {
        if (s[i] != t)
          --k;

        if (k < 0) {
          // skip ts
          while (s[j] == t)
            ++j;

          // skip non-t
          ++j;
          k = 0;
        }

        res = max(res, i - j + 1);
      }

      return res;
    }

  public:
    int maxConsecutiveAnswers(string answerKey, int k) {
      return max(
        impl(answerKey, k, 'T'),
        impl(answerKey, k, 'F')
      );
    }
};


int main() {
  EXECS(Solution::maxConsecutiveAnswers);
  return 0;
}