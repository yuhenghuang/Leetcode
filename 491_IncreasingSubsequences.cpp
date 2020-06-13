#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
  private:
    vector<vector<int>> res;
    vector<int> vec;
    int N;
  public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
      N = nums.size();
      dfs(0, nums);
      return res;
    }

    void dfs(int idx, vector<int>& nums) {
      if (vec.size()>1) res.push_back(vec);

      unordered_set<int> seen;
      for (int i=idx; i<N; ++i)
        if (seen.find(nums[i])==seen.end() && (vec.empty() || vec.back()<=nums[i])) {
          seen.insert(nums[i]);
          vec.push_back(nums[i]);
          dfs(i+1, nums);
          vec.pop_back();
        }
    }
};