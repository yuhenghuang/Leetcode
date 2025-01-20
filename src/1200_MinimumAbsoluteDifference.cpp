#include <local_leetcode.hpp>

class Solution {
  public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
      sort(arr.begin(), arr.end());

      vector<vector<int>> res;

      int diff = INT_MAX;
      for (size_t i = 1; i < arr.size(); ++i) {
        if (arr[i] - arr[i-1] > diff)
          continue;
        else {
          if (arr[i] - arr[i-1] < diff) {
            diff = arr[i] - arr[i-1];
            res.clear();
          }
          
          res.push_back({arr[i-1], arr[i]});
        }
      }

      return res;
    }
};


int main() {
  EXECS(Solution::minimumAbsDifference);
  return 0;
}