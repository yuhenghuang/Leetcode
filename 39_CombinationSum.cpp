#include "utils.hpp"

using namespace std;

class Solution {
  private:
    int n, target;
    vector<int> stack;

    void dfs(const int& idx, const int& sum, vector<int>& nums, vector<vector<int>>& res) {
      if (sum==target) {
        res.push_back(stack);
        return;
      }

      for (int i=idx; i<n; ++i) {
        if (sum+nums[i]>target) continue;
        stack.push_back(nums[i]);
        dfs(i, sum+nums[i], nums, res);
        stack.pop_back();
      }
    }
  public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
      n = candidates.size();
      this->target = target;
      vector<vector<int>> res;

      dfs(0, 0, candidates, res);

      return res;
    }
};


int main() {
  Solution sol;

  vector<string> args;
  vector<int> nums;
  int target;
  
  utils::parse_vector_1d<int> parser;
  vector<vector<int>> res;

  ifstream f("Inputs/39_CombinationSum.txt");
  string line;
  while (getline(f, line)) {
    args = utils::string_split(line);
    nums = parser(args[0]);
    target = stoi(args[1]);

    res = sol.combinationSum(nums, target);

    utils::print_vector_2d(res);
  }

  return 0;
}