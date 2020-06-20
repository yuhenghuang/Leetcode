#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

static int emm = [](){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}();

class Solution {
  public:
    bool canPartition(vector<int>& nums) {
      int N = nums.size();
      if (N<2) return false;

      int sum=0;
      for (int i=0; i<N; ++i) {
        sum += nums[i];
      }
      if (sum%2!=0) return false;

      // sort(nums.begin(), nums.end());
      int target = sum/2;
      vector<bool> dp(target+1, false);
      dp[0] = true;
      for (int i=0; i<N; ++i) {
        int num = nums[i];
        for (int j=target-num; j>=0; --j)
          if (dp[j])
            dp[j+num] = true;
      }
      return dp[target];
    }
};

int main() {
  Solution sol;
  vector<int> nums = {1,5,11,5};
  cout << sol.canPartition(nums) << endl;
  return 0;
}