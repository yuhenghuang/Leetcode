#include <local_leetcode.hpp>

class Solution {
  public:
    vector<string> restoreIpAddresses(string s) {
      int n = s.size();

      if (n < 4 || n > 12)
        return {};

      vector<vector<int>> dp[n + 1];

      dp[0].emplace_back();

      for (int i = 0; i < n; ++i) {
        for (int l = 0; l <= 2 && i - l >= 0; ++l) {
          int num = 256;
          if (l == 0) // one digit
            num = s[i] - '0';
          else if (s[i-l] != '0') // no leading zero
            num = stoi(s.substr(i - l, l + 1));

          if (num <= 255) {
            for (auto& vec : dp[i - l])
              if (vec.size() < 4)
                dp[i + 1].emplace_back(vec).push_back(num);
          }
        }
      }

      vector<string> res;
      for (auto& vec : dp[n])
        if (vec.size() == 4) {
          string& ip = res.emplace_back();
          for (auto& num : vec) {
            ip.append(to_string(num));
            ip.push_back('.');
          }
          ip.pop_back();
        }

      return res;
    }
};


int main() {
  EXECS(Solution::restoreIpAddresses);
  return 0;
}