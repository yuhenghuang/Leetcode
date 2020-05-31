#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

static int emm = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}();

class Comparator {
  private:
    vector<int>& norm;
  public:
    Comparator(vector<int>& n): norm(n) {}
    bool operator () (const int& i, const int& j) const {
      return norm[i] < norm[j];
    }
};

class Solution {
  private:
    int computeNorm(vector<int>& p) {
      return p[0] * p[0] + p[1] * p[1];
    }
  public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
      int n = points.size();
      vector<int> norm(n);
      vector<int> idx(n);
      for (int i=0; i<n; ++i) {
        norm[i] = computeNorm(points[i]);
        idx[i] = i;
      }
      sort(idx.begin(), idx.end(), Comparator(norm));
      vector<vector<int>> res(K);
      for (int i=0; i<K; ++i)
        res[i] = points[idx[i]];
      return res;
    }
};