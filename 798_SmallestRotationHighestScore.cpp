#include "utils.hpp"
#include <map>
#include <climits>

using namespace std;

class Solution {
  public:
    int bestRotation(vector<int>& A) {
      int n = A.size();
      // use array for small n.
      map<int, int> treemap;

      for (int i=0; i<n; ++i) {
        if (A[i]==n) continue;

        if (A[i]>i) {
          ++treemap[i+1];
          --treemap[n-A[i]+i+1];
        }
        else { 
          ++treemap[0];
          --treemap[i-A[i]+1];
          ++treemap[i+1];
        }
      }

      int res = 0, cur = 0, sum = 0;
      for (auto p : treemap) {
        sum += p.second;
        if (sum > cur) {
          cur = sum;
          res = p.first;
        }
      }

      return res;
    }
};


int main() {
  Solution sol;

  vector<int> A;
  utils::parse_vector_1d<int> parser;

  readlines("Inputs/798_SmallestRotationHighestScore.txt") {
    A = parser(line);
    
    cout << sol.bestRotation(A) << endl;
  }

  return 0;
}