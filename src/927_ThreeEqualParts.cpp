#include <numeric>
#include "utils3.hpp"

class Solution {
  private:
    bool compareSubarray(const vector<int>& arr, int i, int j, int k) {
      while (k--) 
        if (arr[i++] != arr[j++])
          return false;

      return true;
    }

  public:
    vector<int> threeEqualParts(vector<int>& arr) {
      int sum = reduce(arr.begin(), arr.end());

      if (sum % 3 != 0)
        return {-1, -1};
      else if (sum == 0)
        return {0, 2};

      int n = arr.size();
      int j = n;

      for (int part = sum / 3; part > 0; --j) 
        if (arr[j-1] > 0)
          --part;

      int i = 0;
      while (arr[i] == 0)
        ++i;

      int k = i + n - j;
      while (arr[k] == 0)
        ++k;
      
      if (compareSubarray(arr, i, j, n-j) && compareSubarray(arr, k, j, n-j))
        return {i + n-j - 1, k + n-j};
      else
        return {-1, -1};
    }
};


int main() {
  UFUNCS(Solution::threeEqualParts);
  return 0;
}