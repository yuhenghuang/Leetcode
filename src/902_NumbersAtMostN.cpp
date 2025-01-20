#include <local_leetcode.hpp>

class Solution {
  private:
    int recursion(int idx, const string& target, const bool* ds, const int* cumsum, const int* acc) {
      if (idx<0)
        return 1;

      int i = target.size()-1-idx;
      int digit = target[i] - '1';
      if (digit<0) return 0;

      if (ds[digit]) {
        return (cumsum[digit]-1) * acc[idx] + recursion(idx-1, target, ds, cumsum, acc);
      }
      else 
        return cumsum[digit] * acc[idx];
    }

  public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
      int p = digits.size();
      bool ds[9] = {0};
      int cumsum[9] = {0};
      for (const string& digit : digits) {
        int idx = digit[0] - '1';
        ds[idx] = true;
        cumsum[idx] = 1;
      }

      for (int i=1; i<9; ++i)
        cumsum[i] = cumsum[i-1] + cumsum[i];

      string target = to_string(n);
      int q = target.size();
      int acc[q];
      acc[0] = 1;

      int res = 0, temp = 1;
      for (int i=1; i<q; ++i) {
        temp *= p;
        acc[i] = temp;
        res += temp;
      }

      res += recursion(q-1, target, ds, cumsum, acc);

      return res;
    }

    int atMostNGivenDigitSetDP(vector<string>& digits, int n) {
      int p = digits.size(); // # of digits
      bool ds[9] = {0}; // if digit i exists
      int cumsum[9] = {0}; // # of digits <= i

      for (const string& digit : digits) {
        int idx = digit[0] - '1';
        ds[idx] = true;
        cumsum[idx] = 1;
      }

      for (int i=1; i<9; ++i)
        cumsum[i] = cumsum[i-1] + cumsum[i];

      string target = to_string(n);
      int q = target.size(); // size of target
      int cumprod[q];
      cumprod[0] = 1;

      int res = 0;
      // # of numbers whose length < q
      for (int i=1; i<q; ++i) {
        cumprod[i] = p * cumprod[i-1];
        res += cumprod[i];
      }

      int dp[q+1];
      dp[q] = 1;
      dp[0] = 0;

      for (int i=q-1; i>=0; --i) {
        int idx = target[i] - '1';
        if (idx<0) break;

        if (ds[idx]) {
          dp[i] = dp[i+1];
          dp[i] += (cumsum[idx]-1) * cumprod[q-1-i];
        }
        else 
          dp[i] = cumsum[idx] * cumprod[q-1-i];
      }

      return res + dp[0];
    }
};


int main() {
  EXECS(Solution::atMostNGivenDigitSet);
  EXECS(Solution::atMostNGivenDigitSetDP);
  return 0;
}