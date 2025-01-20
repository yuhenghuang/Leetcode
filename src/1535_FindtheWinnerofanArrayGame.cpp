#include <local_leetcode.hpp>

class Solution {
  public:
    int getWinner(vector<int>& arr, int k) {
      const int n = arr.size();

      int i = 0;
      for (int j = 1; j < n; i = j++) {
        for (;j < n and arr[i] > arr[j]; ++j);

        if (j == n or j - i - (i == 0 ? 1 : 0) >= k)
          return arr[i];
      }

      return arr[n-1];
    }
};


int main() {
  EXECS(Solution::getWinner);
  return 0;
}