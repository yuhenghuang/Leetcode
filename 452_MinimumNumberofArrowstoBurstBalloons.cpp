/*
#include "utils.hpp"
#include <algorithm>
#include <climits>

using namespace std;
*/

#include <local_leetcode.hpp>

class Solution {
  public:
    int findMinArrowShots(vector<vector<int>>& _points) {
      typedef pair<int, int> ii_t;

      vector<ii_t> points;
      transform(
        _points.begin(), _points.end(),
        back_inserter(points),
        [](const vector<int>& p) -> ii_t { return {p[0], p[1]};  }
      );

      sort(points.begin(), points.end(),
        [](const ii_t& lhs, const ii_t& rhs) {
          return lhs.second < rhs.second;
        }
      );

      int res = 0;
      int end = INT_MIN;
      for (auto& [s, e] : points) {
        if (s > end) {
          ++res;
          end = e;
        }
        else
          end = min(end, e);
      }

      if (!points.empty() && points[0].first == INT_MIN)
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