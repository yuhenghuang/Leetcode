#include "utils.hpp"

class Solution {
  public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
      int n = arr.size();
      vector<vector<int>>::iterator p = pieces.end();
      vector<int>::iterator q;
      for (int num : arr) {
        if (p == pieces.end()) {
          p = find_if(pieces.begin(), pieces.end(), [num](const vector<int>& v){ return v[0]==num; });
          if (p!=pieces.end())
            q = (*p).begin();
        }

        if (p==pieces.end() || q==(*p).end() || *q++!=num)
          return false;

        if (q==(*p).end())
          p = pieces.end();
      }
      return true;
    }
};


int main() {
  UFUNC(Solution::canFormArray);
  return 0;
}