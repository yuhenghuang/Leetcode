#include "DataStructure.h"
#include <vector>
#include <iostream>
using namespace std;

class Solution {
  private:
    vector<vector<int>> memo;
  public:
    int numTrees(int n) {
      memo = vector<vector<int>>(n+1, vector<int>(n+1, 0));
      return numTrees(1, n); 
    }

    int numTrees(int l, int r) {
      if (l>=r) return 1;
      if (memo[l][r]>0) return memo[l][r];
      int res=0;
      for (int i=l; i<=r; ++i) {
        res += numTrees(l, i-1) * numTrees(i+1, r);
      }
      memo[l][r] = res;
      return res;
    }
};

int main() {
  Solution sol;
  cout << sol.numTrees(10) << endl;
  return 0;
}