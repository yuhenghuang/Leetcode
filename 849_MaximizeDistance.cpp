#include "utils.hpp"

class Solution {
  public:
    int maxDistToClosestPointer(vector<int>& seats) {
      int n = seats.size();

      int q = 0;
      while (1 != seats[q])
        ++q;

      int res = 0==q ? 0 : q;
      int p=q;
      while (p<n) {
        while (q<n && seats[q]) ++q;

        p = q;

        while (q<n && !seats[q]) ++q;

        res = max(res, q==n ? q-p : (q-p+1)/2);
      }

      return res;
    }

    int maxDistToClosest(vector<int>& seats) {
      int n = seats.size();
      vector<int> forward(n), backward(n);

      int st=-1, ed=-1;
      for (int i=0; i<n; ++i) {
        if (seats[i]==0) {
          forward[i] = st==-1 ? INT_MAX : i - st;
        }
        else {
          st = i;
        }


        if (seats[n-i-1]==0) {
          backward[n-i-1] = ed==-1 ? INT_MAX : i - ed;
        }
        else {
          ed = i;
        }
      }

      int res=0;
      for (int i=0; i<n; ++i)
        if (seats[i]==0)
          res = max(res, min(forward[i], backward[i]));

      return res;
    }
};


int main() {
  {
    UFUNC(Solution::maxDistToClosest);
  }
  {
    UFUNC(Solution::maxDistToClosestPointer);
  }
  return 0;
}