#include <set>
#include "utils2.hpp"

class Solution {
  public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
      // height and width
      int m = matrix.size(), n = matrix[0].size();

      // prefix sum of each row, O(m * n)
      vector<vector<int>> prefixRowSum(m, vector<int>(n + 1));
      for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j) 
          prefixRowSum[i][j+1] = prefixRowSum[i][j] + matrix[i][j];


      int res = INT_MIN;
      set<int> treeSet;

      // rectangle's horizontal side [cs, ce]
      // O(n^2 * mlogm)
      for (int cs = 0; cs < n; ++cs)
        for (int ce = cs; ce < n; ++ce) {
          int currSum = 0;

          // compute maximum area
          int area = INT_MIN;
          for (int i = 0; i < m; ++i) {
            currSum += prefixRowSum[i][ce + 1] - prefixRowSum[i][cs];
            if (currSum > area)
              area = currSum;

            if (currSum < 0)
              currSum = 0;
          }

          // if maximum area is smaller than k, then there is no need to search further.
          if (area <= k)
            res = max(res, area);
          else {
            treeSet.clear();
            treeSet.insert(0);

            // loop vertically
            for (int i = 0; i < m; ++i) {
              currSum += prefixRowSum[i][ce + 1] - prefixRowSum[i][cs];

              // find the prefix sum such that the rectangle is no larger than k in tree set in O(logn) time
              auto iter = treeSet.lower_bound(currSum - k);
              
              // if such prefix sum exists, update the result
              if (iter != treeSet.end())
                res = max(res, currSum - *iter);

              // insert current prefix sum into the tree set
              treeSet.insert(currSum);
            }
          }
        }

      return res;
    }
};


int main() {
  UFUNC(Solution::maxSumSubmatrix);
  return 0;
}