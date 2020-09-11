#include <vector>
#include <iostream>
#include <climits>

using namespace std;

// specialization to distinguish max(int, int, _comp)
template<typename T>
constexpr const T &max(const T& a, const T& b, const T& c) {
  return max(max(a, b), c);
}

template<typename T, typename... Types>
constexpr const T &max(const T &a, const T &b, const Types &...args) {
  return max(max(a, b), args...);
}

class Solution {
  private:
    int overlapped(const int& a, const int& b) {
      int c = a & b, res = 0;
      while (c>0) {
        res += c & 1;
        c >>= 1;
      }
      return res;
    }
  public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
      int n = A.size();
      vector<int> a(n, 0), b(n, 0);

      for (int i=0; i<n; ++i) 
        for (int j=0; j<n; ++j) {
          a[i] += A[i][j] << (n-j-1);
          b[i] += B[i][j] << (n-j-1);
        }

      int res = 0, t1, t2, t3, t4;
      for (int i=0; i<n; ++i) 
        for (int j=0; j<n; ++j) {
          t1 = 0; t2 = 0; t3 = 0; t4 = 0;
          for (int k=0; k<n-i; ++k) {
            t1 += overlapped(a[k+i] >> j, b[k]);
            t2 += overlapped(b[k+i] >> j, a[k]);
            t3 += overlapped(a[k+i], b[k] >> j);
            t4 += overlapped(b[k+i], a[k] >> j);
          }
          res = max(res, t1, t2, t3, t4);
        }

      return res;
    }
};


int main() {
  Solution sol;
  vector<vector<int>> A = {{1,1,0}, {0,1,0}, {0,1,0}};
  vector<vector<int>> B = {{0,0,0}, {0,1,1}, {0,0,1}};
  cout << sol.largestOverlap(A, B) << endl;
  return 0;
}