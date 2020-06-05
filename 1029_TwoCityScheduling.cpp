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

bool Comparator(const vector<int>& a, const vector<int>& b) {
  return (a[0]-a[1]) < (b[0]-b[1]);
}

class Solution {
  public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
      int i = 0, j = costs.size()-1, res=0;
      sort(costs.begin(), costs.end(), Comparator);
      while (i<j) 
        res += costs[i++][0] + costs[j--][1];
      return res;
    }
};

int main() {
  vector<vector<int>> costs = {{10, 20}, {30, 200}, {400, 50}, {30, 20}};
  Solution sol;
  cout << sol.twoCitySchedCost(costs) << endl;
  return 0;
}