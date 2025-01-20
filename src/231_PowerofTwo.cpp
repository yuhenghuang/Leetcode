#include <iostream>
using namespace std;

class Solution {
  public:
    bool isPowerOfTwo(int n){
      if (n<1) return false;
      else if (n<3) return true;
      int p = 2, bound = INT32_MAX/2;
      while (p<n && p<bound) {
        p *= 2;
        if (p==n) return true;
      }
      return false;
    }
};

int main(){
  Solution sol;
  cout << sol.isPowerOfTwo(256) << endl;
  return 0;
}