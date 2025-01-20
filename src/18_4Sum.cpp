#include <unordered_set>
#include "utils3.hpp"

class Solution {
  private:
    void twoSum(int i, int j, int t, vector<int>& nums, vector<vector<int>>& res) {
      unordered_set<int> s;
      unordered_set<int>::iterator it;

      for (int k = i + 1; k < j; ++k) {
        it = s.find(nums[k]);
        if (it != s.end()) {
          res.push_back({nums[i], t - nums[k], nums[k], nums[j]});
          s.erase(it);
        }

        if (k > i+1 && nums[k] == nums[k-1])
          continue;
        
        s.insert(t - nums[k]);
      }
    }

    vector<vector<int>> twoSum(int i, int t, const vector<int>& nums) {
      vector<vector<int>> res;

      // search in [0, i]
      int l = 0, r = i;
      while (l < r) {
        int sum = nums[l] + nums[r];
        if (sum < t || (l > 0 && nums[l-1] == nums[l]))
          ++l;
        else if (sum > t || (r < i && nums[r+1] == nums[r]))
          --r;
        else
          res.push_back({nums[l++], nums[r--]});  
      }

      return res;
    }


    vector<vector<int>> kSum(int i, int t, int k, const vector<int>& nums) {
      vector<vector<int>> res;
      // length shorter than k or target out of reach
      if (i + 1 < k || nums.front() * k > t || nums.back() * k < t)
        return res;
      else if (k == 2)
        return twoSum(i, t, nums);

      // loop from back
      for (int j = i; j > k - 2; --j)
        // skip repeted occurences
        if (j == i || nums[j+1] != nums[j])
          for (vector<int>& comb : kSum(j - 1, t - nums[j], k - 1, nums))
            res.emplace_back(std::move(comb)).push_back(nums[j]);

      return res;
    }

  public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
      sort(nums.begin(), nums.end());

      int n = nums.size();
      vector<vector<int>> res;
      for (int i = 0; i < n - 3; ++i) {
        if (i > 0 && nums[i-1] == nums[i])
          continue;

        for (int j = n - 1; j > i + 2; --j) {
          if (j < n - 1 && nums[j] == nums[j+1]) 
            continue;

          twoSum(i, j, target - nums[i] - nums[j], nums, res);
        }
      }

      return res;
    }

    vector<vector<int>> fourSumFast(vector<int>& nums, int target) {
      sort(nums.begin(), nums.end());

      return kSum(nums.size() - 1, target, 4, nums);
    }
};


int main() {
  UFUNCS(Solution::fourSum);
  UFUNCS(Solution::fourSumFast);
  return 0;
}