#include <vector>
using namespace std;

class Solution {
  public:
    int findMinFibonacciNumbers(int k) {
      vector<int> vec;
      vec.push_back(1);
      int fn_2 = 0, fn;
      do {
        fn = fn_2 + vec.back();
        fn_2 = vec.back();
        vec.push_back(fn);
      } while (fn<=k);
      vec.pop_back();

      int idx=vec.size(), res=0;
      while (--idx>=0 && k) {
        if (vec[idx]<=k){
          k-=vec[idx];
          ++res;
        }
      }
      return res;
    }
};