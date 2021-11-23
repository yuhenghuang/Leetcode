#include <numeric>
#include <list>
#include "utils3.hpp"

class Solution {
  private:
    int validate_index(int i) {
      return (i < 0 || i == 1e9) ? -1 : i;
    }

  public:
    vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
      int k = queries.size();

      // indices of queries
      vector<int> indicies(k);
      iota(indicies.begin(), indicies.end(), 0);

      // sort indicies by min size
      sort(
        indicies.begin(), indicies.end(),
        [&queries] (int i, int j) -> bool {
          return queries[i][1] < queries[j][1];
        }
      );

      map<int, int> m;
      for(auto& r : rooms) 
        m[r[0]] = r[1];

      // use 1e9 as keys to avoid overflow
      m[1e9] = INT_MAX;
      m[-1e9] = INT_MAX;

      vector<int> res(k);
      for (int i : indicies) {
        // preferred room id
        int t = queries[i][0];
        // minimum size required
        int s = queries[i][1];

        // two pointers around the preferred room
        auto r = m.lower_bound(t);
        auto l = prev(r);

        // hard to formulate the end condition of loop...
        while (true) {
          // check right first
          if (r->first - t < t - l->first) {
            if (r->second < s)
              // maybe use r++ to keep consistency?
              r = m.erase(r);
            else {
              res[i] = validate_index(r->first);
              break;
            }
          }
          else {
            if (l->second < s) 
              m.erase(l--);
            else {
              res[i] = validate_index(l->first);
              break;
            }
          }
        }
      }

      return res;
    }
};


int main() {
  UFUNCS(Solution::closestRoom);
  return 0;
}