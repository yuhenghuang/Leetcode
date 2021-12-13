#include "utils3.hpp"

class Solution {
  public:
    int minimumBuckets(string street) {
      // O2n
      int n = street.size();
      int res = 0;
      for (int i = 1; i < n - 1; ++i)
        if (street[i] == '.' && street[i-1] == 'H' && street[i+1] == 'H') {
          street[i-1] = street[i+1] = 'X';
          ++res;
        }

      for (int i = 0; i < n; ++i)
        if (street[i] == 'H') {
          if ((i > 0 && street[i-1]  == '.') || (i < n - 1 && street[i+1] == '.'))
            ++res;
          else
            return -1;
        }

      return res;
    }

    int minimumBucketsOn(string street) {
      // On
      int n = street.size();
      int res = 0;

      int i = 0;
      while (i < n) {
        if (street[i] == 'H') {
          if (i < n - 1 && street[i+1] == '.') {
            i += 3;
            ++res;
          }
          else if (i > 0 && street[i-1] == '.') {
            ++i;
            ++res;
          }
          else
            return -1;
        }
        else
          ++i;
      }

      return res;
    }
};


int main() {
  UFUNCS(Solution::minimumBuckets);
  UFUNCS(Solution::minimumBucketsOn);
  return 0;
}