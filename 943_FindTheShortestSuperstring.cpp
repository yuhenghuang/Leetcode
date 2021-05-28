#include <unordered_set>
#include "utils2.hpp"

class Solution {
  private:
    string overlapped(const string& x, const string& y) {
      int m = x.size(), n = y.size();
      for (int i = max(0, m - n); i < m; ++i) {
        int j = 0;
        while (i + j <= m - 1 - j && x[i+j] == y[j] && x[m-1-j] == y[m-i-1-j]) {
          ++j;
        }

        if (i + j > m - 1 - j) 
          return x.substr(0, i) + y;
      }

      return x + y;
    }

  public:
    string shortestSuperstring(vector<string>& words) {
      // TLE
      // the crucial condition is "no substring in words"
      // even if there is, substrings should be eliminated beforehand.
      int n = words.size();
      int N = 1 << n;

      vector<unordered_set<string>> dp(N);
      dp.front().insert("");

      vector<bool> seen(N);

      queue<int> q;
      q.push(0);
      while (!q.empty()) {
        int S = q.size();
        while (S--) {
          int v = q.front();
          q.pop();

          for (int i = 0; i < n; ++i)
            if (((v >> i) & 1) == 0) {
              int w = v ^ (1 << i);
              for (const string& s : dp[v]) {
                dp[w].insert(overlapped(s, words[i]));
                dp[w].insert(overlapped(words[i], s));
              }

              if (!seen[w]) {
                seen[w] = true;
                q.push(w);
              }
            }
        }
      }


      unordered_set<string>& results = dp.back();

      string res(241, '#');
      for (const string& s : results)
        if (s.size() < res.size())
          res = s;

      return res;
    }
};


int main() {
  UFUNC(Solution::shortestSuperstring);
  return 0;
}