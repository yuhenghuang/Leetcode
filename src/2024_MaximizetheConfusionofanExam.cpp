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

    int upper_bound(const vector<int>& prefix, int target) {
      return ::upper_bound(prefix.begin(), prefix.end(), target) - prefix.begin();
    }

  public:
    int maxConsecutiveAnswers(string answerKey, int k) {
      return max(
        impl(answerKey, k, 'T'),
        impl(answerKey, k, 'F')
      );
    }

    int maxConsecutiveAnswersPrefix(string answerKey, int k) {
      const int n = answerKey.size();

      vector<int> prefix1(n + 1), prefix0(n + 1);
      for (int i = 0; i < n; ++i) {
        prefix1[i + 1] += prefix1[i] + (answerKey[i] == 'T' ? 1 : 0);
        prefix0[i + 1] = i + 1 - prefix1[i + 1];
      }

      // hint: prefix[j] - prefix[i] == sum over [i, j)

      int res = 0;
      for (int i = 0; i < n; ++i) {
        res = max(
          res,
          max(upper_bound(prefix1, prefix1[i] + k), upper_bound(prefix0, prefix0[i] + k)) - i -1
        );
      }

      return res;
    }
};


int main() {
  EXECS(Solution::maxConsecutiveAnswers);
  EXECS(Solution::maxConsecutiveAnswersPrefix);
  return 0;
}