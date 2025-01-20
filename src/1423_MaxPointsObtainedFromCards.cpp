#include "utils2.hpp"

class Solution {
  public:
    int maxScore(vector<int>& cardPoints, int k) {
      int n = cardPoints.size();
      k = n - k;

      int sum = 0;
      int temp = 0;

      int i = 0;
      for (; i < k; ++i) {
        sum += cardPoints[i];
        temp += cardPoints[i];
      }

      int res = temp;
      for (; i < n; ++i) {
        temp += cardPoints[i] - cardPoints[i - k];
        res = min(res, temp);

        sum += cardPoints[i];
      }

      return sum - res;
    }
};


int main() {
  UFUNC(Solution::maxScore);
  return 0;
}