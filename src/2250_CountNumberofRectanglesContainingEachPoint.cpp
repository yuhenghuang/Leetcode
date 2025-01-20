#include <local_leetcode.hpp>

class Solution {
  private:
    void update(vector<int>& bit, int i) {
      for (; i < bit.size(); i += i & (-i))
        ++bit[i];
    }

    int query(vector<int>& bit, int i) {
      int res = 0;
      for (; i > 0; i -= i & (-i))
        res += bit[i];

      return res;
    }

  public:
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
      set<int> s;
      transform(
        rectangles.begin(), rectangles.end(), 
        inserter(s, s.end()), 
        mem_fn( static_cast<const int& (vector<int>::*)() const>(&vector<int>::front) )
      );

      transform(
        points.begin(), points.end(), 
        inserter(s, s.end()), 
        mem_fn<const int& () const, vector<int>>(&vector<int>::front)
      );

      // length -> index;
      unordered_map<int, int> m;
      auto iter = s.begin();
      for (int i = 0; iter != s.end(); ++i, (void) ++iter)
        m[*iter] = i;

      // binary index tree
      vector<int> bit(s.size() + 1);

      vector<int> index(points.size());
      iota(index.begin(), index.end(), 0);

      sort(
        index.begin(), index.end(),
        [&points](const int& i, const int& j) -> bool {
          return points[i][1] > points[j][1];
        }
      );

      // rectangle lengths at height i
      vector<vector<int>> lengths(101);
      for (auto& rect : rectangles)
        lengths[rect[1]].push_back(rect[0]);

      vector<int> res(points.size());

      // count visited rectangles
      int n = 0;

      auto i = index.begin();
      for (int h = 100; h > 0; --h) {
        for (const int& l: lengths[h]) {
          update(bit, m[l] + 1);
          ++n;
        }

        for (; i != index.end() && points[*i][1] >= h; ++i)
          res[*i] = n - query(bit, m[points[*i][0]]);
      }

      return res;
    }
};


int main() {
  EXECS(Solution::countRectangles);
  return 0;
}