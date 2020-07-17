#include <vector>
using namespace std;

class Solution {
  public:
    vector<vector<int>> subsets(vector<int>& nums) {
      vector<int> temp;
      vector<vector<int>> res;
      res.push_back({});
      for (int i=0; i<nums.size(); ++i) {
        int N = res.size();
        for (int j=0; j<res.size(); ++j) {
          temp = res[j];
          temp.push_back(nums[i]);
          res.push_back(temp);
        }
      }
      return res;
    }
};