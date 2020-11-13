#include "utils.hpp"
#include <algorithm>

class Solution {
  private:
    int distance(vector<int>& p, vector<int>& q) {
      int i = p[0] - q[0], j = p[1] - q[1];
      return i*i + j*j;
    }
  public:
    bool validSquareFast(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
      vector<vector<int>> points {p1, p2, p3, p4};
      sort(points.begin(), points.end(),
           [](const vector<int>& p, const vector<int>& q) -> bool {
             return p[0] == q[0] ? p[1] < q[1] : p[0] < q[0];
           });

      int d = distance(points[0], points[1]);
      return d == distance(points[1], points[3]) && 
             d == distance(points[0], points[2]) && 
             d == distance(points[2], points[3]) &&
             distance(points[0], points[3]) == distance(points[1], points[2]);
    }

    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
      vector<vector<int>> points {p1, p2, p3, p4};
      double x0 = 0., y0 = 0.;
      for (const vector<int>& p : points) {
        x0 += p[0] / 4.0;
        y0 += p[1] / 4.0;
      }

      vector<double> len(4);
      vector<vector<double>> vecs(4);
      for (int i=0; i<4; ++i) {
        vecs[i].push_back(points[i][0] - x0);
        vecs[i].push_back(points[i][1] - y0);

        len[i] = vecs[i][0] * vecs[i][0] + vecs[i][1] * vecs[i][1];
        if (i>0 && len[i]!=len[i-1])
          return false;
      }

      bool left, back, right;
      for (int i=0; i<4; ++i) {
        double slope = vecs[i][1] / vecs[i][0];

        left = back = right = true;
        for (int j=0; j<4; ++j)
          if (j!=i) {
            double prod = vecs[i][0] * vecs[j][0] + vecs[i][1] * vecs[j][1];
            if (prod == 0) {
              if (vecs[j][1] > vecs[j][0] * slope)
                left = false;
              else
                right = false;
            }
            else if (prod == -len[i]) {
              back = false;
            }
          }

        if (left || back || right)
          return false;
      }

      return true;
    }
};


int main() {
  {
    UFUNC(Solution::validSquare);
  }
  {
    UFUNC(Solution::validSquareFast);
  }
  return 0;
}