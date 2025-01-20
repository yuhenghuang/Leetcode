#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

static int emm = [](){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}();

class Solution {
  public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
      vector<vector<int>> res(people.size(), vector<int>(2, __INT_MAX__));
      sort(people.begin(), people.end());
      for (auto& p : people) {
        int cnt = p[1], idx = 0;
        while (cnt>0) 
          if (res[idx++][0]>=p[0])
            --cnt;
        while (res[idx][0]!=__INT_MAX__)
          ++idx;
        res[idx] = p;
      }
      return res;
    }
};