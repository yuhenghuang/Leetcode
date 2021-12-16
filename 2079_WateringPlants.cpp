#include "utils3.hpp"

class Solution {
  public:
    int wateringPlants(vector<int>& plants, int capacity) {
      int n = plants.size();

      int can = capacity;
      int res = 0;
      for (int i = 0; i < n; ++i) {
        if (can < plants[i]) {
          can = capacity - plants[i];
          res += i * 2 + 1;
        }
        else {
          can -= plants[i];
          ++res;
        }        
      }

      return res;
    }
};


int main() {
  UFUNCS(Solution::wateringPlants);
  return 0;
}