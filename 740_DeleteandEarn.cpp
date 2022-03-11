#include <local_leetcode.hpp>

class Solution {
  public:
    int deleteAndEarn(vector<int>& _nums) {
      int _min = _nums[0];
      int _max = _nums[0];
      for (int i = 1; i < _nums.size(); ++i) {
        if (_nums[i] > _max)
          _max = _nums[i];
        else if (_nums[i] < _min)
          _min = _nums[i];
      }

      const int n = _max - _min + 1;

      vector<int> nums(n);

      for (const int& num : _nums)
        ++nums[num - _min];

      int prev = 0;
      int curr = 0;

      for (int i = 0; i < n; ++i) {
        int next = max(curr, prev + nums[i] * (i + _min));

        prev = curr;
        curr = next;
      }

      return curr;
    }

    int deleteAndEarnFast(vector<int>& nums) {
      // num, count
      unordered_map<int, int> m;
      for (const int& num : nums)
        ++m[num];

      vector<pair<int, int>> vec;
      // preallocate memory to avoid unnecessary copy
      vec.reserve(m.size() + 1);

      vec.assign(m.begin(), m.end());
      vec.emplace_back(-1, 0);

      sort(vec.begin(), vec.end());

      int prev = 0;
      int curr = 0;
      for (int i = 1; i < vec.size(); ++i) {
        auto& [num, freq] = vec[i];
        int next = (vec[i-1].first + 1 == num) ? max(curr, prev + num * freq) : (curr + num * freq);

        prev = curr;
        curr = next;
      }

      return curr;
    }
};


int main() {
  EXECS(Solution::deleteAndEarn);
  EXECS(Solution::deleteAndEarnFast);
  return 0;
}