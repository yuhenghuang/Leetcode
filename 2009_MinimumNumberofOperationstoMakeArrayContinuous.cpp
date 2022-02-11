#include <local_leetcode.hpp>

class Solution {
  public:
    int minOperationsFast(vector<int>& nums) {
      int n = nums.size();

      map<int, int> m;
      m[INT_MAX] = n;

      for (int i = 0; i < n; ++i)
        m[nums[i]];

      int uid = 0;
      for (auto& p : m)
        p.second = uid++;

      int res = n;

      auto end = prev(m.end());
      for (auto i = m.begin(); i != end; ++i) {
        
        res = min(res,
          n - max(
            // [i->first, i->first + n)
            m.lower_bound(i->first + n)->second - i->second,
            // (i->first - n, i->first]
            i->second + 1 - m.upper_bound(i->first - n)->second
          )
        );
      }

      return res;
    }

    int minOperations(vector<int>& nums) {
      int n = nums.size();

      // max numbers in [i, i + n)
      int res = n;
      sort(nums.begin(), nums.end());

      // distinct count
      int count = 0;

      unordered_map<int, int> prefix;
      prefix[nums[0]] = count++;

      for (int i = 1; i < nums.size(); ++i)
        if (nums[i-1] < nums[i])
          prefix[nums[i]] = count++;

      // distinct count
      int dist;
      vector<int>::iterator boundary;
      for (auto iter = nums.begin(); iter != nums.end(); ++iter) {
        // [*iter, *iter+n)
        boundary = lower_bound(iter, nums.end(), *iter + n);

        dist = (boundary == nums.end() ? count : prefix[*boundary]) - prefix[*iter];

        res = min(res, n - dist);

        // (*iter-n, *iter]
        boundary = upper_bound(iter, nums.end(), *iter - n);

        dist = (*iter - n < nums[0] ? prefix[*iter] : prefix[*iter] - prefix[*boundary]) + 1;

        res = min(res, n - dist);
      }

      return res;
    }
};


int main() {
  EXECS(Solution::minOperations);
  EXECS(Solution::minOperationsFast);
  return 0;
}