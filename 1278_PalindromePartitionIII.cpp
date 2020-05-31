#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
  private:
    int n;
    string s;
    vector<vector<int>> memo;
    vector<vector<bool>> seen;
  public:
    int palindromePartition(string s, int k) {
      n = s.size();
      this->s = s;
      memo = vector<vector<int>>(n, vector<int>(k, 0));
      seen = vector<vector<bool>>(n, vector<bool>(k, false));
      return dp(n-1, k-1);
    }

    int dp(int i, int d) {
      if (seen[i][d]) return memo[i][d];
      seen[i][d] = true;
      int res = 100;
      if (d==0)
        res = helper(0, i);
      else {
        for (int j=0; j<i; ++j) {
          res = min(res, dp(j, d-1) + helper(j+1, i));
        }
      }
      memo[i][d] = res;
      return res;
    }

    int helper(int l, int r) {
      int dis=0;
      while (l<r) {
        if (s[l]!=s[r])
          ++dis;
        ++l; --r;
      }
      return dis;
    }
};

int main() {
  Solution sol;
  cout << sol.palindromePartition("leetcode", 8) << endl;
}