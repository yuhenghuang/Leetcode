#include <local_leetcode.hpp>

class Solution {
  public:
    int sumSubarrayMins(vector<int>& arr) {
      constexpr int mod = 1e9 + 7;

      stack<int> s;
      int n = arr.size();
      int res = 0, dot = 0;

      for (int i=0; i<n; ++i) {
        int q = i-1;
        while (!s.empty() && arr[s.top()] >= arr[i]) {
          int p = s.top(); s.pop();
          dot -= (q-p) * arr[q];
          q = p;
        }

        int j = s.empty() ? -1 : s.top();
        dot -= (q-j) * (q < 0 ? 0 : arr[q]);
        dot += (i-j) * arr[i];

        res += dot;
        res %= mod;

        s.push(i);
      }

      return res;
    }
};


int main() {
  EXECS(Solution::sumSubarrayMins);
  return 0;
}