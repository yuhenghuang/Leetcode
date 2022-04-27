#include <local_leetcode.hpp>

class Solution {
  private:
    // return m[t / 2] if t is even, otherwise 0
    int findHalf(unordered_map<long long, int>& m, long long t) {
      if (t % 2 == 0) {
        t /= 2;
        auto iter = m.find(t);
        return iter == m.end() ? 0 : iter->second;
      }
      else
        return 0;
    }

  public:
    int waysToPartition(vector<int>& nums, int k) {
      // prefix + suffix == total
      // suffix == total - prefix
      //
      // modifying nums[i] in prefix to k such that prefix + k - nums[i] == suffix
      //
      // suffix == total - prefix == prefix + k - nums[i]
      // 2 * prefix == total - k + nums[i]
      //
      // the modification occurs in prefix sum!!

      const int n = nums.size();

      long long sum = 0; // total sum

      // prefix (suffix) sum, count
      unordered_map<long long, int> p, s;

      for (int i = 0; i < n - 1; ++i)
        ++p[sum += nums[i]];

      sum += nums[n-1];

      int res = max(findHalf(p, sum), findHalf(p, sum - k + nums[0]));

      long long suffix = sum;
      for (int i = 1; i < n; ++i) {
        suffix -= nums[i - 1];

        // only prefix/suffix sums that incorporate nums[i] will be affected
        // thus, prefix/suffix sum is updated as index goes up

        ++s[suffix]; // add suffix sum over [i, n-1]
        --p[sum - suffix]; // remove prefix sum over [0, i-1]

        // target, 2 * prefix (or suffix) sum
        long long t = sum - k + nums[i];

        res = max(res, findHalf(p, t) + findHalf(s, t));
      }

      return res;
    }
};


int main() {
  EXECS(Solution::waysToPartition);
  return 0;
}