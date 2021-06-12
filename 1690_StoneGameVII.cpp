#include "utils2.hpp"

inline int add(const int& x, const int& y) { return x + y; }
inline int sub(const int& x, const int& y) { return x - y; }

namespace utils2 {

  // base class
  template <typename Arg1, typename Arg2, typename Res>
  struct binary_function { 
    virtual Res operator()(const Arg1&, const Arg2&) const { 
      throw std::runtime_error("No Implementation of Functor in Base Class binary_function");
      
      return Res(); 
    };
  };

  // derived +
  template <typename Tp>
  struct plus : binary_function<Tp, Tp, Tp> {
    virtual Tp operator()(const Tp& x, const Tp& y) const {
      return x + y;
    }
  };

  // derived -
  template <typename Tp>
  struct minus : binary_function<Tp, Tp, Tp> {
    virtual Tp operator()(const Tp& x, const Tp& y) const {
      return x - y;
    }
  };
}

class Solution {
  private:
    int dp(int i, int j, bool isAlice, const vector<int>& prefixSum, vector<vector<int>>& memo) {
      if (i == j)
        return 0;
      else if (memo[i][j] > 0)
        return memo[i][j];

      const int& (*comp)(const int&, const int&);
      // int (*op)(const int&, const int&);
      utils2::binary_function<int, int, int>* op;
      if (isAlice) {
        comp = max;
        // op = add;
        op = new utils2::plus<int>();
      }
      else {
        comp = min;
        // op = sub;
        op = new utils2::minus<int>();
      }

      

      int res = comp(
        op->operator()(dp(i+1, j, !isAlice, prefixSum, memo), prefixSum[j+1] - prefixSum[i+1]),
        op->operator()(dp(i, j-1, !isAlice, prefixSum, memo), prefixSum[j] - prefixSum[i])
      );

      memo[i][j] = res;
      delete op;

      return res;
      // return memo[i][j] = comp(
      //   op(dp(i+1, j, !isAlice, prefixSum, memo), prefixSum[j+1] - prefixSum[i+1]),
      //   op(dp(i, j-1, !isAlice, prefixSum, memo), prefixSum[j] - prefixSum[i])
      // );
    }

  public:
    int stoneGameVII(vector<int>& stones) {
      int n = stones.size();

      vector<int> prefixSum(n+1);
      for (int i = 0; i < n; ++i)
        prefixSum[i+1] = prefixSum[i] + stones[i];

      // alice and bob's relative score to each other
      vector<vector<int>> memo(n, vector<int>(n));

      return dp(0, n - 1, true, prefixSum, memo);
    }

    int stoneGameVIIIterative(vector<int>& stones) {
      int n = stones.size();

      vector<int> prefixSum(n+1);
      for (int i = 0; i < n; ++i)
        prefixSum[i+1] = prefixSum[i] + stones[i];

      vector<vector<int>> memo(n, vector<int>(n));
      for (int l = n - 2; l >= 0; --l)
        for (int r = l + 1; r < n; ++r)
          memo[l][r] = max(
            prefixSum[r+1] - prefixSum[l+1] - memo[l+1][r], 
            prefixSum[r] - prefixSum[l] - memo[l][r-1]
          );
        
      return memo[0][n-1];
    }
};


int main() {
  {
    UFUNC(Solution::stoneGameVII);
  }
  {
    UFUNC(Solution::stoneGameVIIIterative);
  }
  return 0;
}