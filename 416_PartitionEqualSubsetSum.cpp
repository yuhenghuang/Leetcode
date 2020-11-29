#include "utils.hpp"

static int emm = [](){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}();

enum COLOR {
  WHITE,
  BLACK,
  GREY
};

class Solution {
  private:
    int N, target;
    vector<vector<COLOR>> memo;
  public:
      bool canPartition(vector<int>& nums) {
      N = nums.size();
      if (N<2) return false;

      int sum = accumulate(nums.begin(), nums.end(), 0);
      if (sum%2!=0) return false;
      target = sum/2;
      memo = vector<vector<COLOR>>(N, vector<COLOR>(target+1, GREY));
      return dfs(0, 0, nums);
    }

    bool dfs(int idx, int sum, vector<int>& nums) {
      if (sum>target || idx==N) return false;
      if (memo[idx][sum]!=GREY) return memo[idx][sum]==WHITE;

      if (sum==target) 
        return true;
      else {
        bool flag = dfs(idx+1, sum+nums[idx], nums) ||  dfs(idx+1, sum, nums);
        memo[idx][sum] = flag ? WHITE : BLACK;
        return flag;
      }
    }

    bool canPartitionSlow(vector<int>& nums) {
      int N = nums.size();
      if (N<2) return false;

      int sum=0;
      for (int num : nums)
        sum += num;
      if (sum%2!=0) return false;

      int target = sum/2;
      vector<bool> dp(target+1, false);
      dp[0] = true;
      for (int num : nums) {
        for (int j=target-num; j>=0; --j)
          if (dp[j])
            dp[j+num] = true;
      }
      return dp[target];
    }
};

int main() {
  {
    UFUNC(Solution::canPartition);
  }
  {
    UFUNC(Solution::canPartitionSlow);
  }
  return 0;
}