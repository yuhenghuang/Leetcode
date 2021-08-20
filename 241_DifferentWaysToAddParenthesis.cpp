#include "utils3.hpp"

class Solution {
  private:
    vector<int>& dfs(const string& s, int i, int j, vector<vector<int>>& memo) {
      vector<int>& res = memo[i * s.size() + j];
      if (!res.empty())
        return res;

      // whether s btw i and j is a single number
      bool flag = false;
      for (int k = i; k <= j; ++k) {
        int p = k;
        while (p <= j && isdigit(s[p]))
          ++p;

        if (p > j) {
          if (k == i)
            flag = true;
        }
        else {
          for (int l : dfs(s, i, p-1, memo))
            for (int r : dfs(s, p+1, j, memo)) {
              int num;
              switch (s[p]) {
                case '+':
                  num = l + r; break;
                case '-':
                  num = l - r; break;
                case '*':
                  num = l * r; break;
                default:
                  abort();
              }

              res.push_back(num);
            }
        }

        k = p;
      }

      if (flag)
        res.push_back(stoi(s.substr(i, j-i+1)));

      return res;
    }

  public:
    vector<int> diffWaysToCompute(string expression) {
      int n = expression.size();
      vector<vector<int>> memo(n * n);

      return dfs(expression, 0, expression.size() - 1, memo);
    }
};


int main() {
  UFUNCS(Solution::diffWaysToCompute);
  return 0;
}