#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
  public:
    int leastBricks(vector<vector<int>>& wall) {
      unordered_map<int, int> m;
      for (auto& row : wall) {
        int temp = 0;
        for (int i=0; i<row.size()-1; ++i) {
          temp += row[i];
          ++m[temp];
        }
      }

      int res = 0;
      for (auto iter=m.begin(); iter!=m.end(); ++iter)
        if (res < iter->second)
          res = iter->second;
      return wall.size() - res;
    }
};