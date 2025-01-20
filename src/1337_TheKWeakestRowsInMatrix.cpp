#include <local_leetcode.hpp>

class Solution {
  private:
    int binarySearch(const vector<int>& vec) {
      int l = 0, r = vec.size();
      while (l < r) {
        int m = l + (r-l) / 2;

        if (vec[m])
          l = m+1;
        else
          r = m;
      }

      return l;
    }

  public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
      int m = mat.size();

      vector<int> soldiers(m);
      vector<int> indices(m);
      for (int i=0; i<m; ++i) {
        indices[i] = i;
        soldiers[i] = binarySearch(mat[i]);
      }

      sort(indices.begin(), indices.end(),
        [&soldiers](const int x, const int y) -> bool {
          return soldiers[x] < soldiers[y] || (soldiers[x] == soldiers[y] && x < y);
        }
      );

      vector<int> res;
      res.reserve(k);
      
      for (int i=0; i<k; ++i)
        res.push_back(indices[i]);

      return res;
    }

    vector<int> kWeakestRowsPair(vector<vector<int>>& mat, int k) {
      int m = mat.size();

      vector<pair<int, int>> soldiers;
      soldiers.reserve(m);
      for (int i=0; i<m; ++i)
        soldiers.emplace_back(binarySearch(mat[i]), i);

      sort(soldiers.begin(), soldiers.end());

      vector<int> res;
      res.reserve(k);

      for (int i=0; i<k; ++i)
        res.push_back(soldiers[i].second);

      return res;
    }
};


int main() {
  EXECS(Solution::kWeakestRows);
  EXECS(Solution::kWeakestRowsPair);
  return 0;
}