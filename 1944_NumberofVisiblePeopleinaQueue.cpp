#include "utils3.hpp"

class Solution {
  private:
    // binary search the index of element larger than t in [l, r)
    int bs(vector<int>& heights, int l, int r, int t) {
      while (l < r) {
        int m = l + (r - l) / 2;

        if (heights[m] < t)
          l = m + 1;
        else
          r = m;
      }

      return l;
    }

  public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
      int n = heights.size();

      int l = n - 1, r = n;
      vector<int> res(n);

      for (int i = n - 2; i >= 0; --i) {
        int j = bs(heights, l, r, heights[i]);

        // +1 if height taller than ith person is found
        res[i] = j - l + (j == r ? 0 : 1);

        l = j - 1;
        heights[l] = heights[i];
      }

      return res;
    }


    vector<int> canSeePersonsCountFast(vector<int>& heights) {
      int n = heights.size();

      int l = n - 1;
      vector<int> res(n);

      for (int i = n - 2; i >= 0; --i) {
        int j = l;

        while (j < n && heights[i] > heights[j])
          ++j;

        // +1 if height taller than ith person is found
        res[i] = j - l + (j == n ? 0 : 1);

        l = j - 1;
        heights[l] = heights[i];
      }

      return res;
    }
};


int main() {
  UFUNCS(Solution::canSeePersonsCount);
  UFUNCS(Solution::canSeePersonsCountFast);
  return 0;
}