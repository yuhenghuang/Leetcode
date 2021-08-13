#include <unordered_set>
#include "utils3.hpp"

class Solution {
  public:
    bool canReorderDoubled(vector<int>& arr) {
      sort(arr.begin(), arr.end(),
        [](int x, int y) {
          return abs(x) < abs(y);
        }
      );

      unordered_multiset<int> s;
      for (int num : arr) {
        auto iter = s.find(num);
        if (iter == s.end())
          s.insert(num * 2);
        else
          s.erase(iter);
      }

      return s.size() == 0;
    }
};


int main() {
  UFUNCS(Solution::canReorderDoubled);
  return 0;
}