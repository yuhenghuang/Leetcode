/*
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;

static int emm = [](){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}();
*/

#include <local_leetcode.hpp>

bool Comparator(const vector<int>& a, const vector<int>& b) {
  return (a[0]-a[1]) < (b[0]-b[1]);
}

class Solution {
  public:
    int twoCitySchedCostOld(vector<vector<int>>& costs) {
      int i = 0, j = costs.size()-1, res=0;
      sort(costs.begin(), costs.end(), Comparator);
      while (i<j) 
        res += costs[i++][0] + costs[j--][1];
      return res;
    }

    int twoCitySchedCost(vector<vector<int>>& costs) {
      const int n = costs.size();

      vector<int> diffs;
      diffs.reserve(n);

      int res = 0;
      for (auto& c : costs) {
        diffs.push_back(c[0] - c[1]);
        res += c[1];
      }

      sort(diffs.begin(), diffs.end());

      for (int i = 0; i < (n / 2); ++i)
        res += diffs[i];

      return res;
    }

    int twoCitySchedCostFast(vector<vector<int>>& costs) {
      const int n = costs.size() / 2;

      // max heap
      priority_queue<int> heap;

      int res = 0;
      for (auto& c : costs) {
        int d = c[0] - c[1];

        if (heap.size() < n)
          heap.push(d);
        else if (heap.top() > d) {
          heap.pop();
          heap.push(d);
        }

        res += c[1];
      }

      while (!heap.empty()) {
        res += heap.top();
        heap.pop();
      }

      return res;
    }
};

int main() {
  /*
  vector<vector<int>> costs = {{10, 20}, {30, 200}, {400, 50}, {30, 20}};
  Solution sol;
  cout << sol.twoCitySchedCost(costs) << endl;
  */

  EXECS(Solution::twoCitySchedCostOld);
  EXECS(Solution::twoCitySchedCost);
  EXECS(Solution::twoCitySchedCostFast);
  return 0;
}