#include <local_leetcode.hpp>

class Solution {
  private:
    int lower_bound(vector<int>& arr, int l, int r, int t) {
      while (l < r) {
        int m = l + (r - l) / 2;

        if (arr[m] <= t)
          l = m + 1;
        else
          r = m;
      }

      return l;
    }

  public:
    int findBestValue(vector<int>& arr, int target) {
      int n = arr.size();

      sort(arr.begin(), arr.end());

      vector<int> prefix(n + 1);
      for (int i = 0; i < n; ++i)
        prefix[i+1] = prefix[i] + arr[i];

      // distance
      int d = INT_MAX;

      int res;

      int l = 0, r = arr[n-1];
      while (l <= r) {
        int m = l + (r - l) / 2;

        int i = lower_bound(arr, 0, n, m);

        int temp = prefix[i] + (n - i) * m;

        if (temp < target) {
          // in case a tie, choose smaller m
          if (target - temp <= d) {
            d = target - temp;
            res = m;
          }

          l = m + 1;
        }
        else if (temp > target) {
          if (temp - target < d) {
            d = temp - target;
            res = m;
          }

          r = m - 1;
        }
        else
          return m;
      }

      return res;
    }
};


int main() {
  EXECS(Solution::findBestValue);
  return 0;
}