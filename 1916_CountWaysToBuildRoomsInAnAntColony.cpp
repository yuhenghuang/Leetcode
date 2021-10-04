#include "utils3.hpp"


static constexpr int mod = 1e9 + 7;

class Solution {
  private:
    int gcdExtended(int a, int b, int& x, int& y) {
      if (a == 0) {
        x = 0; y = 1;
        return b;
      }

      int xx, yy;
      int gcd = gcdExtended(b % a, a, xx, yy);

      x = yy - (b/a) * xx;
      y = xx;

      return gcd;
    }

    int modInverse(int b) {
      int x, y;
      int g = gcdExtended(b, mod, x, y);

      return (x % mod + mod) % mod;
    }

    // nAk 
    long permutation(int n, int k) {
      long res = 1;
      for (; k > 0; --k, --n) {
        res *= n;
        if (res > mod)
          res %= mod;
      }

      return res;
    }

    // return size of subtree
    int dfs(int v, const vector<vector<int>>& graph, vector<long>& dp) {
      long res = 1;
      // count of total nodes in subtrees
      int n = 0;

      vector<int> count;
      for (int w : graph[v]) {
        int temp = dfs(w, graph, dp);
        n += temp;
        count.push_back(temp);

        res *= dp[w];
        if (res > mod)
          res %= mod;
      }

      // in theory, we should loop over count except the largest element
      // by multiplying nCk to res,
      // where n is the remained num. of elements
      // and k is the num. of nodes in the corresponding subtree
      if (count.size() > 1) {
        sort(count.begin(), count.end());
        res *= permutation(n, n - count.back());
        if (res > mod)
          res %= mod;

        long div = 1;
        for (int i = 0; i < int(count.size()) - 1; ++i) {
          // precompute permutation to save time?
          // or more aggressively compute the inverse of factorial(i) to 1e5?
          div *= permutation(count[i], count[i]);

          if (div > mod)
            div %= mod;
        }

        res = (modInverse(div) * res) % mod;
      }

      dp[v] = res;
      return 1 + n;
    }

  public:
    int waysToBuildRooms(vector<int>& prevRoom) {
      // no cycle exists because there are n - 1 edges!!!
      int n = prevRoom.size();

      vector<vector<int>> graph(n);
      for (int i = 1; i < n; ++i)
        graph[prevRoom[i]].push_back(i);

      vector<long> dp(n);

      dfs(0, graph, dp);

      return dp[0];
    }
};


int main() {
  UFUNCS(Solution::waysToBuildRooms);
  return 0;
}