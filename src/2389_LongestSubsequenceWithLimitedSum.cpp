#include <local_leetcode.hpp>

class Solution {
  public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
      nums.push_back(1e9);
      sort(nums.begin(), nums.end());

      int m = queries.size();
      
      vector<int> indices(m);
      iota(indices.begin(), indices.end(), 0);
      sort(
        indices.begin(), indices.end(),
        [&queries] (int i, int j) { return queries[i] < queries[j]; }
      );

      vector<int> res(m);

      int j = 0;
      int sum = 0;
      for (const int& i : indices) {
        for (; sum <= queries[i]; ++j)
          sum += nums[j];

        res[i] = j - 1;
      }
      
      return res;
    }
};


int main() {
  EXECS(Solution::answerQueries);
  return 0;
}