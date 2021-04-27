#include "utils2.hpp"

class Solution {
  public:
    vector<int> constructArray(int n, int k) {
      vector<int> res;
      res.reserve(n);
      
      for (int i=0; i<k; ++i) 
        res.push_back(i % 2 == 0 ? (i/2 + 1) : (n - i/2));
      
      if (k % 2 == 0) {
        for (int i = n - k/2; i > (k+1)/2; --i)
          res.push_back(i);
      }
      else {
        for (int i = (k+1)/2 + 1; i <= (n - k/2); ++i)
          res.push_back(i);
      }
      
      return res;
    }
};


int main() {
  UFUNC(Solution::constructArray);
  return 0;
}