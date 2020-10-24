#include "utils.hpp"
#include <map>

class Solution {
  private:
    bool verifyInterval(map<int, int>& m, int num) {
      auto iter = m.upper_bound(num);
      return iter!= m.end() && iter->second < num;
    }
  public:
    bool find132patternSimple(vector<int>& nums) {
      map<int, int> m;

      int n = nums.size(), j=1;
      while (j<n && nums[j-1]>=nums[j])
        ++j;

      bool climbing = true;
      for (int i=j; i<n; ++i) {
        if (!climbing && nums[i-1]>nums[i]) {
          j = i-1;
          climbing = !climbing;
        }

        if (climbing && nums[i-1]<nums[i]) {
          m.insert({nums[j], nums[i-1]});
          climbing = !climbing;
        }

        if (!m.empty() && verifyInterval(m, nums[i]))
          return true;
      }

      return false;
    }

    bool find132pattern(vector<int>& nums) {
      map<int, int> m;

      int n = nums.size();
      int i=0, j;
      while (i<n) {
        if (!m.empty() && verifyInterval(m, nums[i]))
          return true;

        while (i<n-1 && nums[i] >= nums[i+1]) {
          if (!m.empty() && verifyInterval(m, nums[i+1]))
            return true;
          ++i;
        }

        j = i;
        while (j<n-1 && nums[j] <= nums[j+1]) {
          if (!m.empty() && verifyInterval(m, nums[j+1]))
            return true;
          ++j;
        }

        m.insert({nums[j], nums[i]});
        i = j+1;
      }

      return false;
    }
};


int main() {
  Solution sol;

  vector<int> nums;
  utils::parse_vector_1d<int> parser;

  readlines("Inputs/456_132Pattern.txt") {
    nums = parser(line);

    cout << boolalpha << sol.find132pattern(nums) << " " << sol.find132patternSimple(nums) << endl;
  }

  return 0;
}