#include "utils.hpp"

using namespace std;

class Solution {
  private:
    int minDominoRotations(int t, vector<int>& A, vector<int>& B) {
      int n=A.size(), res=0;
      for (int i=0; i<n; ++i) {
        if (A[i]==t)
          continue;
        else if (B[i]==t)
          ++res;
        else
          return INT_MAX;
      }

      return res;
    }
  public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
      int a=A[0], b=B[0];

      int res=INT_MAX;
      if (a==b) {
        res = min(minDominoRotations(a, A, B), 
                  minDominoRotations(a, B, A));
      }
      else {
        res = min(minDominoRotations(a, A, B),
                  minDominoRotations(b, A, B));

        res = min(res, minDominoRotations(a, B, A));
        res = min(res, minDominoRotations(b, B, A));
      }

      return res==INT_MAX ? -1 : res;
    }
};


int main() {
  Solution sol;

  vector<int> A, B;
  vector<string> args;

  utils::parse_vector_1d<int> parser;

  readlines("Inputs/1007_MinDominoEqualRow.txt") {
    args = utils::string_split(line);
    A = parser(args[0]);
    B = parser(args[1]);

    cout << sol.minDominoRotations(A, B) << endl;
  }
  
  return 0;
}