#include <local_leetcode.hpp>

class Solution {
  public:
    int maxFrequencySort(vector<int>& nums, int k) {
      sort(nums.begin(), nums.end());

      int n = nums.size();

      int res = 0;

      int j = 0;
      long long ops = 0;

      for (int i = 0; i < n; ++i) {
        if (i > 0)
          ops += (long long)(nums[i] - nums[i-1]) * (i - j);

        while (ops > k) 
          ops -= nums[i] - nums[j++];

        res = max(res, i - j + 1);
      }

      return res;
    }

    int maxFrequency(vector<int>& nums, int k) {
      map<int, int> m;
      for (const int& num : nums)
        ++m[num];

      int res = 0;

      // num of previous numbers
      long long dist = 0;

      // num of operations to reach current number
      long long ops = 0;
      // previous number
      int prev = 0;

      auto i = m.begin();
      auto j = m.begin();
      for (; i != m.end(); ++i) {
        int curr = i->first;
        ops += (curr - prev) * dist;

        while (ops > k) {
          long long diff = (curr - j->first);

          if (ops - diff * j->second >= k) {
            ops -= diff * j->second;
            dist -= j->second;

            ++j;
          }
          else {
            int multiplier = (ops - k) / diff + ((ops - k) % diff ? 1 : 0);

            ops -= diff * multiplier;
            dist -= multiplier;

            j->second -= multiplier;
            if (j->second == 0)
              ++j;
          }

        }

        dist += i->second;

        if (dist > res)
          res = dist;

        prev = curr;
      }

      return res;
    }
};


int main() {
  EXECS(Solution::maxFrequency);
  EXECS(Solution::maxFrequencySort);
  return 0;
}