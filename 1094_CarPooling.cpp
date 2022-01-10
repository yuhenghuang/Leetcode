#include <local_leetcode.hpp>

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
      map<int, int> treemap;
      for (auto& t: trips) {
        treemap[t[1]] += t[0];
        treemap[t[2]] -= t[0];
      }

      int curr=0;
      for (auto iter = treemap.begin(); iter!=treemap.end(); ++iter) {
        curr += iter->second;
        if (curr > capacity)
          return false;
      }

      return true;
    }
};

int main() {
  /*
  Solution sol;

  string line;
  int capacity;
  vector<vector<int>> trips;
  utils::parse_vector_2d<int> parser;

  while (getline(cin, line)) {
    trips = parser(line);
    cin >> capacity;
    
    cout << sol.carPooling(trips, capacity) << endl;
    cin.get();
  }
  */

  EXECS(Solution::carPooling);
  return 0;
}