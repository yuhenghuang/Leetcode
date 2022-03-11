#include <local_leetcode.hpp>

class Solution {
  private:
    uint64_t mapNums(vector<int>& mapping, int num) {
      if (num == 0)
        return mapping[0];

      uint64_t base = 1;

      uint64_t out = 0;
      while (num > 0) {
        out += mapping[num % 10] * base;

        base *= 10;
        num /= 10;
      }

      return out;
    }

  public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
      int n = nums.size();

      // use 64bit integer to save jumbled numbers to avoid overflow
      vector<uint64_t> jumbled(n);
      for (int i = 0; i < n; ++i)
        jumbled[i] = mapNums(mapping, nums[i]);

      vector<int> indicies(n);
      iota(indicies.begin(), indicies.end(), 0);

      stable_sort(
        indicies.begin(),
        indicies.end(),
        [&jumbled](const int& i, const int& j) -> bool {
          return jumbled[i] < jumbled[j];
        }
      );

      vector<int> res(n);
      for (int i = 0; i < n; ++i)
        res[i] = nums[indicies[i]];

      return res;
    }
};


int main() {
  EXECS(Solution::sortJumbled);
  return 0;
}