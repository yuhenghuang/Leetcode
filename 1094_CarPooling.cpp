#include <vector>
#include <map>
#include <iostream>
#include "utils.hpp"

using namespace std;

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
      map<int, int> treemap;
      for (auto& trip: trips) {
        treemap[trip[1]] += trip[0];
        treemap[trip[2]] -= trip[0];
      }

      int curr=0;
      for (auto iter = treemap.begin(); iter!=treemap.end(); ++iter) {
        curr += iter->second;
        if (curr>capacity)
          return false;
      }

      return true;
    }
};

int main() {
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

  return 0;
}