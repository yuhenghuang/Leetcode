#include "utils.hpp"

using namespace std;

class Solution {
  public:
    int maxProfit(int k, vector<int>& prices) {
      int n = prices.size();
      k = k > n/2 ? n : 2*k;

      vector<vector<int>> dp(n+1, vector<int>(k+1, 0));

      for (int i=0; i<n; ++i) {
        for (int j=0; j<=i; ++j) {
          dp[i+1][j] = max(dp[i][j], dp[i+1][j]);
          if (j==k) break;
          dp[i+1][j+1] = dp[i][j] + ( j%2==0 ? -prices[i] : prices[i]);
        }
      }

      int res=0;
      for (int i=0; i<=k; ++i)
        res = max(res, dp[n][i]);

      return res;
    }
};


int main() {
  Solution sol;

  vector<int> prices;
  int k;
  vector<string> args;

  utils::parse_vector_1d<int> parser;

  readlines("Inputs/188_BestTimeStockIV.txt") {
    args = utils::string_split(line);
    prices = parser(args[0]);
    k = stoi(args[1]);

    cout << sol.maxProfit(k, prices) << endl;
  }

  return 0;
}