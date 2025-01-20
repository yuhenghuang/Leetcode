#define _LL_NONTRIVIAL_SOLUTION_CTOR
#define _LL_FLATTEN_2D
#include <local_leetcode.hpp>

#include <limits>

class Solution {
  private:
    vector<vector<int>> res;
    vector<int> vec;
    int N;

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

    int highest_bit(int x) {
      return std::numeric_limits<int>::digits - __builtin_clz(x);
    }

  public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
      vec.clear();
      res.clear();

      N = nums.size();
      dfs(0, nums);
      return res;
    }

    vector<vector<int>> findSubsequencesBit(vector<int>& nums) {
      // wrong answer!!!

      int n = nums.size();
      int N = 1 << n;

      // bit, index in res
      unordered_map<int, size_t> m;
      vector<vector<int>> res;

      for (int b = 1; b < N; ++b) {
        int i = highest_bit(b);
        int p = b ^ (1 << i);
        if (p > 0) {
          int j = highest_bit(p);

          if (nums[i] >= nums[j]) {
            m[b] = res.size();

            if (p ^ (1 << j))
              res.emplace_back(res[m[p]]).push_back(nums[i]);
            else
              res.push_back({nums[j], nums[i]});
          }
        }
      }

      return res;
    }
};


int main() {
  EXECS(Solution::findSubsequences);
  EXECS(Solution::findSubsequencesBit);
  return 0;
}
