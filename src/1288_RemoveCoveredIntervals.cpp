#include "utils.hpp"
#include <algorithm>


using namespace std;

class Solution {
  public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
      int n = intervals.size(), res = n;

      if (n>0) {
        sort(intervals.begin(), intervals.end(), 
          [](const vector<int>& lhs, const vector<int>& rhs){
            return lhs[0] == rhs[0] ? lhs[1] > rhs[1] : lhs[0] < rhs[0];
          }
        );

        vector<int> itv = intervals[0];
        for (int i=1; i<n; ++i) {
          if (intervals[i][1] > itv[1]) 
            itv = intervals[i];
          else
            --res;
        }

      }

      return res;
    }
};


int main() {
  Solution sol;

  vector<vector<int>> itvs;
  utils::parse_vector_2d<int> parser;

  ifstream f("Inputs/1288_RemoveCoveredIntervals.txt");
  string line;
  while (getline(f, line)) {
    itvs = parser(line);

    cout << sol.removeCoveredIntervals(itvs) << endl;
  }

  return 0;
}