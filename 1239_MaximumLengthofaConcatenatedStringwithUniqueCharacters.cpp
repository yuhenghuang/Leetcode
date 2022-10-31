#include <local_leetcode.hpp>

class Solution {
  public:
    int maxLength(vector<string>& _arr) {
      vector<int> arr;

      for (auto& s : _arr) {
        bool flag = true;
        int bits = 0;
        for (char c : s) {
          int b = 1 << (c - 'a');

          // duplicate characters found in single string
          if (b & bits) {
            flag = false;
            break;
          }
          else
            bits |= b;
        }

        if (flag)
          arr.push_back(bits);
      }

      int n = arr.size();
      int N = 1 << n;

      // combination of bits, 
      int dp[N];
      memset(dp, -1, sizeof(dp));

      dp[0] = 0;
      int res = 0;

      for (int i = 1; i < N; ++i) {
        int j = __builtin_ctz(i); // rightmost 1-bit index

        if ((arr[j] & dp[i ^ (1 << j)]) == 0) {
          dp[i] = arr[j] | dp[i ^ (1 << j)];

          res = max(res, __builtin_popcount(dp[i]));
        }
      }

      return res;
    }
};


int main() {
  EXECS(Solution::maxLength);
  return 0;
}