#include <local_leetcode.hpp>

class SpiralIterator {
  public:
    typedef int value_type;
    typedef ptrdiff_t difference_type;
    typedef int* pointer;
    typedef int& reference;
    typedef forward_iterator_tag iterator_category;

  private:
    static constexpr int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    vector<vector<int>>& mat;
    int i; // index on current direction
    int l; // length on current direction
    int d; // diretion

    int r, c;

  public:
    SpiralIterator(vector<vector<int>>& _mat): 
      mat(_mat), 
      i(0), l(mat.size()), 
      d(0), r(0), c(0) 
    { }

    SpiralIterator& operator++() {
      ++i;
      
      if (i == l) {
        i = 0;
        d = (d + 1) % 4;

        // shrink l when d is odd
        if (d % 2 == 1)
          --l;
      }

      r += dirs[d][0];
      c += dirs[d][1];

      return *this;
    }

    int& operator*() { return mat[r][c]; }

    bool hasNext() const { return l > 0; }
};


// java-like adapter
template <class Iterator>
bool 
hasNext(const Iterator& iter) { return iter.hasNext(); }


class Solution {
  public:
    vector<vector<int>> generateMatrixIter(int n) {
      vector<vector<int>> res(n, vector<int>(n));

      SpiralIterator iter(res);

      for (int i = 1; hasNext(iter); ++i) {
        *iter = i;
        advance(iter, 1);
      }

      return res;
    }

    vector<vector<int>> generateMatrix(int n) {
      vector<vector<int>> res(n, vector<int>(n));

      static const int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

      int num = 0, __max = n * n;
      
      int i_old = 0, j_old = -1, d = 0;
      while (num < __max) {
        int i = i_old + dir[d][0], j = j_old + dir[d][1];
        if (i<0 || i==n || j<0 || j==n || res[i][j]) {
          d = (d+1) % 4;
          continue;
        }
        res[i][j] = ++num;
        i_old = i;
        j_old = j;
      }

      return res;
    }

    vector<vector<int>> generateMatrixNew(int _n) {
      constexpr int dirs[4][2] {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

      int m = _n - 1;
      int n = _n;

      int i = 0;
      int j = -1;
      int d = 0;

      int num = 0;

      vector<vector<int>> res(n, vector<int>(n));
      while (m >= 0 && n >= 0) {
        int& l = (d & 1) ? m : n;

        for (int k = 0; k < l; ++k) {
          i += dirs[d][0];
          j += dirs[d][1];
          res[i][j] = ++num;
        }

        --l;
        d = (d + 1) % 4;
      }

      return res;
    }
};


int main() {
  EXECS(Solution::generateMatrix);
  EXECS(Solution::generateMatrixIter);
  EXECS(Solution::generateMatrixNew);
  return 0;
}
