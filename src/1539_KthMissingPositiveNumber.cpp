#include <local_leetcode.hpp>

class Solution {
  public:
    int findKthPositive(vector<int>& arr, int k) {
      int n = arr.size();
      int i = 0, res = 0;
      while (k) {
        ++res;
        if (i<n && arr[i]==res) 
          ++i;
        else 
          --k;
      }
      return res;
    }

    int findKthPositiveOn(vector<int>& arr, int k) {
      int l=0;
      for (int num : arr) {
        int dist = num - l - 1;
        if (dist>=k) 
          return l+k;
        else
          k -= dist;

        l = num;
      }
      return l+k;
    }
};


int main() {
  EXECS(Solution::findKthPositive);
  EXECS(Solution::findKthPositiveOn);
  return 0;
}