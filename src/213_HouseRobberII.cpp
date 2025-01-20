#include "utils.hpp"

using namespace std;


class Solution {
  public:
    int rob(vector<int>& nums) {
      int n = nums.size();
      if (n==1) return nums[0];

      vector<int> memo1(n+1, 0), memo2(n+1, 0);

      for (int i=0; i<n-1; ++i) {
        memo1[i+2] = max(nums[i]+memo1[i], memo1[i+1]);
        memo2[i+2] = max(nums[i+1]+memo2[i], memo2[i+1]);
      }

      return max(max(memo1[n], memo2[n]), memo2[n-1]);
    }
};


int main() {
  Solution sol;

  vector<int> nums;
  utils::parse_vector_1d<int> parser;

  readlines("Inputs/213_HouseRobberII.txt") {
    nums = parser(line);

    cout << sol.rob(nums) << endl;
  }

  return 0;
}