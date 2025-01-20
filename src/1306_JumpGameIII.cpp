#include "utils.hpp"

class Solution {
  private:
    int n;

    bool dfs(int idx, vector<int>& arr, vector<bool>& seen) {
      if (idx<0 || idx>=n || seen[idx]) 
        return false;

      seen[idx] = true;
      if (arr[idx]==0) 
        return true;
      return dfs(idx+arr[idx], arr, seen) || dfs(idx-arr[idx], arr, seen);
    }
  public:
    bool canReach(vector<int>& arr, int start) {
      n = arr.size();
      vector<bool> seen(n);

      return dfs(start, arr, seen);
    }
};


int main() {
  UFUNC(Solution::canReach);
  return 0;
}