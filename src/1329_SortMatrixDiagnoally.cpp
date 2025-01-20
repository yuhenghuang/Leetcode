#include <local_leetcode.hpp>

class diag_iterator {
  // ...
  public:
    typedef random_access_iterator_tag iterator_category;
    typedef ptrdiff_t difference_type;
    typedef int value_type;
    typedef int& reference;
    typedef int* pointer;

  private:
    vector<vector<int>>& mat;
    int m, n;
    int i, j;

    difference_type index() const {
      if (j==n)
        return m*n;

      int diag_idx = j-i-1;
      int i_idx = max(0, -diag_idx);
      int j_idx = max(0, diag_idx);

      size_t res = 0;
      if (i_idx) {
        int a = m-i_idx;
        int h = min(a, n);
        int b = a - h + 1;
        res += (a+b) * h /2;
      }
      else { // j_idx>0
        int a = n-j_idx;
        int h = min(a, m);
        int b = a - h + 1;
        res += m*n - (a+b) * h / 2;
      }

      return res + min(i, j);
    }

    int height(int diag_idx) const {
      if (m>n) {
        return diag_idx>0 ? (n-diag_idx) : (diag_idx<n-m ? (diag_idx+m) : n) ;
      }
      else {
        return diag_idx<0 ? (diag_idx+m) : (diag_idx>n-m ? (n-diag_idx) : m);
      }
    }

  public:
    diag_iterator(vector<vector<int>>& _m, int _i, int _j): mat(_m), i(_i), j(_j) {
      m = mat.size();
      n = m==0 ? 0 : mat[0].size();
    }
    
    diag_iterator(const diag_iterator& rhs): 
      mat(rhs.mat), m(rhs.m), n(rhs.n), i(rhs.i), j(rhs.j) { }

    diag_iterator& operator=(const diag_iterator& rhs) {
      // mat = rhs.mat;
      // m = rhs.m;
      // n = rhs.n;
      i = rhs.i;
      j = rhs.j;
      return *this;
    }

    int& operator*() {
      return mat[i][j];
    }

    bool operator==(const diag_iterator& rhs) const {
      return i==rhs.i && j==rhs.j;
    }

    bool operator!=(const diag_iterator& rhs) const {
      return !(*this == rhs);
    }

    bool operator<(const diag_iterator& rhs) const {
      return (j-i) < (rhs.j-rhs.i) || ((j-i)==rhs.j-rhs.i && i < rhs.i);
    }

    bool operator>(const diag_iterator& rhs) const {
      return (j-i) > (rhs.j-rhs.i) || ((j-i)==rhs.j-rhs.i && i > rhs.i);
    }

    bool operator<=(const diag_iterator& rhs) const {
      return !(*this > rhs);
    }

    bool operator>=(const diag_iterator& rhs) const {
      return !(*this < rhs);
    }

    difference_type operator-(const diag_iterator& rhs) const {
      return index() - rhs.index();
    }

    diag_iterator& operator++() {
      int diag_idx = j-i;

      if (j<n) {
        if (min(i, j) + 1 < height(diag_idx)) {
          ++i;
          ++j;
        }
        else {
          ++diag_idx;
          i = max(0, -diag_idx);
          j = max(0, diag_idx);
        }
      }
      return *this;
    }

    diag_iterator operator++(int) {
      diag_iterator tmp(*this);
      this->operator++();
      return tmp;
    }

    diag_iterator& operator--() {
      if (j>0 || i!=m-1) {
        if (i==0 || j==0) {
          int diag_idx = j-i-1;
          int h = height(diag_idx);
          i = max(0, -diag_idx) + h - 1;
          j = max(0, diag_idx) + h - 1;
        }
        else {
          --i;
          --j;
        }
      }
      // else {
      //   i = 0;
      //   j = -1;
      // }

      return *this;
    }

    diag_iterator operator--(int) {
      diag_iterator tmp(*this);
      this->operator--();
      return tmp;
    }


    diag_iterator operator+(ptrdiff_t dist) {
      if (dist == 1) {
        diag_iterator out(*this);
        ++out;
        return out;
      }

      int diag_idx = j-i;
      int diag_h = height(diag_idx) - min(i, j) - 1;

      if (dist <= diag_h)
        return diag_iterator(mat, i+dist, j+dist);

      while (dist > diag_h) {
        dist -= diag_h;
        diag_h = height(++diag_idx);
      }

      return diag_iterator(mat, max(0, -diag_idx)+dist-1, max(0, diag_idx)+dist-1);
    }

    diag_iterator& operator+=(ptrdiff_t dist) {
      *this = *this + dist;
      return *this;
    }

    diag_iterator operator-(ptrdiff_t dist) {
      if (dist==1) {
        return operator--();
      }

      int diag_idx = j-i;
      int diag_h = min(i, j) + 1;

      if (dist <= diag_h)
        return diag_iterator(mat, i-dist, j-dist);

      while (dist > diag_h) {
        dist -= diag_h;
        diag_h = height(--diag_idx);
      }

      return diag_iterator(mat, max(0, -diag_idx)+diag_h-dist-1, max(0, diag_idx)+diag_h-dist-1);
    }

    void print() {
      cout << i << ", " << j << endl;
    }

};


class Solution {
  private:
    void sortInplace(int idx, vector<int>& s, int m, int n, vector<vector<int>>& mat) {
      int i = max(0, -idx);
      int j = max(0, idx);

      int s_i=0;

      for (;i<m && j<n; ++i, ++j, ++s_i)
        s[s_i] = mat[i][j];

      sort(s.begin(), s.begin()+s_i);

      for (; i>0 && j>0; --i, --j, --s_i)
        mat[i-1][j-1] = s[s_i-1];
    }

  public:
    vector<vector<int>> diagonalSortOn(vector<vector<int>>& mat) {
      int m = mat.size(), n = mat[0].size();
      vector<int> s(m);

      for (int idx=-m+1; idx<n; ++idx)
        sortInplace(idx, s, m, n, mat);

      return mat;
    }

    vector<vector<int>> diagonalSortIter(vector<vector<int>>& mat) {
      // not diagonal-wise
      // but all elements

      int m = mat.size(), n = mat[0].size();
      diag_iterator bg(mat, m-1, 0);
      diag_iterator ed(mat, 0, n);

      sort(bg, ed);

      return mat;
    }

    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
      int m = mat.size(), n = mat[0].size();
      vector<vector<int>> container(m+n-1);
      vector<vector<int>> res(m, vector<int>(n));

      for (int i=0; i<m; ++i)
        for (int j=0; j<n; ++j)
          container[j-i+m-1].push_back(mat[i][j]);

      for (auto& diag : container)
        sort(diag.begin(), diag.end());

      for (int i=m-1; i>=0; --i)
        for (int j=0; j<n; ++j) {
          res[i][j] = container[j-i+m-1].back();
          container[j-i+m-1].pop_back();
        }
      return res;
    }
};


int main() {
  EXECS(Solution::diagonalSort);
  EXECS(Solution::diagonalSortOn);
  EXECS(Solution::diagonalSortIter);
  return 0 ;
}
