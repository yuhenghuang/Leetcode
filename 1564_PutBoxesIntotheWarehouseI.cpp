#include "utils3.hpp"

class Solution {
  public:
    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {
      int h = INT_MAX;
      for (int& room : warehouse) {
        if (room < h)
          h = room;
        else
          room = h;
      }

      sort(boxes.begin(), boxes.end());

      int res = 0;

      int j = warehouse.size() - 1;
      for (int i = 0; i < boxes.size() && j >= 0; ++i) {
        while (j >= 0 && warehouse[j] < boxes[i])
          --j;

        if (j-- >= 0)
          ++res;
      }
      
      return res;
    }

};


int main() {
  UFUNCS(Solution::maxBoxesInWarehouse);
  return 0;
}