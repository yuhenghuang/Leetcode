/*
#include "utils.hpp"
#include <algorithm>
#include <climits>

using namespace std;
*/

#include <local_leetcode.hpp>

class Solution {
  public:
    int findMinArrowShots(vector<vector<int>>& points) {
      sort(points.begin(), points.end(),
        [](const vector<int>& lhs, const vector<int>& rhs) {
          return lhs[0] == rhs[0] ? lhs[1] < rhs[1] : lhs[0] < rhs[0];
        }
      );

      int res=0;
      int ed = INT_MIN;
      for (vector<int>& baloon : points) {
        if (baloon[0] > ed) {
          ++res;
          ed = baloon[1];
        }
        else {
          ed = min(ed, baloon[1]);
        }
      }

      if (points.size()>0 && points[0][0]==INT_MIN)
        ++res;

      return res;
    }

    int findMinArrowShotsAlternative(vector<vector<int>>& points) {
      sort(points.begin(), points.end(),
        [](const vector<int>& x, const vector<int>& y) {
          return x[1] < y[1];
        }
      );

      int ed = INT_MIN;
      int res = 0;
      for (auto& p : points) 
        if (p[0] > ed) {
          ++res;
          ed = p[1];
        }

      if (!points.empty() && points[0][0]==INT_MIN)
        ++res;

      return res;
    }
};


int main() {
  /*
  Solution sol;

  vector<vector<int>> points;
  utils::parse_vector_2d<int> parser;

  ifstream f("Inputs/452_MinNumberArrows.txt");
  string line;
  while (getline(f, line)) {
    points = parser(line);

    cout << sol.findMinArrowShots(points) << endl;
  }
  */

  EXECS(Solution::findMinArrowShots);
  EXECS(Solution::findMinArrowShotsAlternative);
  return 0;
}