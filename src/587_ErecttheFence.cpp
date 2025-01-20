#include "utils3.hpp"

class Solution {
  public:
    vector<vector<int>> outerTrees(vector<vector<int>>& _trees) {
      if (_trees.size() <= 3)
        return _trees;

      typedef pair<int, int> ii_t;

      vector<ii_t> trees;
      transform(
        _trees.begin(), _trees.end(), 
        back_inserter(trees), 
        [](const vector<int>& tree) -> ii_t { return {tree.front(), tree.back()}; }
      );

      int x0 = INT_MAX, y0 = INT_MAX;

      int i0 = -1;
      for (int i = 0; i < (int) trees.size(); ++i) {
        auto& [x, y] = trees[i];

        if (y < y0 || (y == y0 && x < x0 )) {
          i0 = i;
          x0 = x;
          y0 = y;
        }
      }

      swap(trees[i0], trees.back());
      trees.pop_back();

      

      stack<ii_t> s;



      vector<vector<int>> res;
      while (!s.empty()) {
        res.push_back({s.top().first, s.top().second});
        s.pop();
      }

      return res;
    }
};


int main() {
  UFUNCS(Solution::outerTrees);
  return 0;
}