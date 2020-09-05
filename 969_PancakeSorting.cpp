#include <vector>
#include <algorithm>
#include <iostream>
#include <iterator>

using namespace std;

class Solution {
private:
  int findMaxLocation(vector<int> &A, int n) {
    int num = A[0], idx = 0;
    for (int i=1; i<n; ++i)
      if (A[i]>num) {
        idx = i;
        num = A[i];
      }
    return idx;
  }
public:
    vector<int> pancakeSort(vector<int>& A) {
      int n = A.size();
      vector<int> res;

      int idx;
      for (int i=n; i>0; --i) {
        idx = findMaxLocation(A, i);
        if (idx==i-1) 
          continue;
        else {
          res.push_back(idx+1);
          reverse(A.begin(), A.begin()+idx+1);
        }
        reverse(A.begin(), A.begin()+i);
        res.push_back(i);
      }
      return res;
  }
};

int main() {
  Solution sol;
  vector<int> A = {3,2,4,1};
  vector<int> res = sol.pancakeSort(A);
  copy(res.begin(), res.end(), ostream_iterator<int>(cout, ", "));
  return 0;
}