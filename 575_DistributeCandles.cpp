#include <unordered_set>
#include "utils2.hpp"

class Solution {
  public:
    int distributeCandies(vector<int>& candyType) {
      unordered_set<int> s;

      for (int t : candyType)
        s.insert(t);
      
      return min(candyType.size() / 2, s.size());
    }
};


int main() {
  UFUNC(Solution::distributeCandies);
  return 0;
}