#include <local_leetcode.hpp>

class Solution {
  private:
    typedef pair<int, int> ii_t;

    ii_t levelIndex(int x) {
      int h = numeric_limits<int>::digits - __builtin_clz(x);
      int i = x - (1 << h);

      return {h, i};
    }

  public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
      vector<int> res;

      for (auto& q : queries) {
        int len = 1;

        ii_t u = levelIndex(q[0]);
        ii_t v = levelIndex(q[1]);

        while (u != v) {
          if (u.first < v.first) {
            --v.first;
            v.second >>= 1;
          }
          else if (u.first > v.first) {
            --u.first;
            u.second >>= 1;
          }
          else {
            u.second >>= 1;
            v.second >>= 1;
            ++len;
          }
          ++len;
        }

        res.push_back(len);
      }

      return res;
    }
};


int main() {
  EXECS(Solution::cycleLengthQueries);
  return 0;
}