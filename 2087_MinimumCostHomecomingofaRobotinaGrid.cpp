#include "utils3.hpp"

static constexpr int dir[4][2] {{0,1}, {0,-1}, {1,0}, {-1,0}};

class Solution {
  private:
    int subarray_sum(vector<int>& vec, int i, int j) {
      if (i > j)
        return subarray_sum(vec, j, i);

      int sum = 0;
      for (; i <= j; ++i)
        sum += vec[i];

      return sum;
    }

  public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
      return subarray_sum(rowCosts, startPos[0], homePos[0]) + 
             subarray_sum(colCosts, startPos[1], homePos[1]) -
             rowCosts[startPos[0]] -
             colCosts[startPos[1]];
    }

    int minCostWrong(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
      // this is not an optimal path search problem
      int m = rowCosts.size();
      int n = colCosts.size();

      bool seen[m][n];
      memset(seen, 0, sizeof(seen));
      seen[startPos[0]][startPos[1]] = true;

      typedef tuple<int, int, int> iii_t;

      priority_queue<iii_t, vector<iii_t>, greater<iii_t>> heap;

      heap.emplace(0, startPos[0], startPos[1]);
      while (!heap.empty()) {
        auto [t, i, j] = heap.top();
        heap.pop();

        if (i == homePos[0] && j == homePos[1])
          return t;

        for (int k = 0; k < 4; ++k) {
          int r = i + dir[k][0];
          int c = j + dir[k][1];

          if (r >= 0 && r < m && c >= 0 && c < n && !seen[r][c]) {
            seen[r][c] = true;
            heap.emplace(
              t + (k < 2 ? colCosts[c] : rowCosts[r]),
              r, c
            );
          }
        }
      }

      return -1;
    }
};


int main() {
  UFUNCS(Solution::minCost);
  UFUNCS(Solution::minCostWrong);
  return 0;
}