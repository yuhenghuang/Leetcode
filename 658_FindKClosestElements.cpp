#include "utils2.hpp"

class Solution {
  public:
    typedef vector<int>::iterator iter_type;

    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
      vector<int> res;
      res.reserve(k);

      int l=0, r=20001, m, diff;
      iter_type low, high;
      while (l<r) {
        m = l + (r-l)/2;
        low = lower_bound(arr.begin(), arr.end(), x-m);
        high = upper_bound(arr.begin(), arr.end(), x+m);

        diff = high - low;

        if (diff < k)
          l = m+1;
        else
          r = m;
      }

      low = lower_bound(arr.begin(), arr.end(), x-l+1);
      high = upper_bound(arr.begin(), arr.end(), x+l-1);
      iter_type lower = lower_bound(arr.begin(), arr.end(), x-l);

      iter_type iter = low - min(max(k - (high - low), 0L), low - lower);
      while (k--) {
        res.push_back(*iter++);
      }

      return res;
    }

    vector<int> findClosestElementsTwoPointers(vector<int>& arr, int k, int x) {
      int n = arr.size();

      int i = 0, j = n;
      while (j - i > k) {
        if (x - arr[i] > arr[j-1] - x)
          ++i;
        else
          --j;
      }

      return {arr.begin() + i, arr.begin() + j};
    }

    vector<int> findClosestElementsBS(vector<int>& arr, int k, int x) {
      int l = 0, r = arr.size() - k;
      while (l < r) {
        int m = l + (r - l) / 2;
        if (x - arr[m] > arr[m + k] - x)
          l = m + 1;
        else
          r = m;
      }

      return {arr.begin() + l, arr.begin() + l + k};
    }
};

int main() {
  {
    UFUNC(Solution::findClosestElements);
  }
  {
    UFUNC(Solution::findClosestElementsTwoPointers);
  }
  {
    UFUNC(Solution::findClosestElementsBS);
  }
  return 0;
}
