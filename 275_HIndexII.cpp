#include <vector>
using namespace std;

class Solution {
  public:
    int hIndex(vector<int>& citations) {
      int n = citations.size(), l=0, r=n-1, m=0;
      if (n==0) return 0;
      while (l<r) {
        m = l + (r-l)/2;
        if (citations[m]<n-m)
          l = m+1;
        else
          r = m;
      }
      return min(n-l, citations[l]);
    }
};