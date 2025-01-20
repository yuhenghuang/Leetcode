#include <string>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
      int m = word1.length(), n = word2.length();
      int memo[m+1][n+1];
      memset(memo, 0, sizeof(int) * (m+1) * (n+1));

      for (int i=1; i<=m; i++)
        memo[i][0] = i;
      for (int j=1; j<=n; j++)
        memo[0][j] = j;
        
      for (int i=1; i<=m; i++)
        for (int j=1; j<=n; j++) {
          if (word1[i-1]==word2[j-1])
            memo[i][j] = memo[i-1][j-1];
          else
            memo[i][j] = 1 + min(memo[i-1][j-1], min(memo[i-1][j], memo[i][j-1]));
        }
      return memo[m][n];
    }
};

int main() {
  Solution sol;
  cout << sol.minDistance("horse", "ros") << endl;
  return 0;
}