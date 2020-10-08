#include "utils.hpp"

using namespace std;

class Solution {
public:
    int bitwiseComplement(int N) {
      if (N==0) return 1;
      int mask=0, n=N;
      while (N>0) {
        mask <<= 1;
        ++mask;

        N >>= 1;
      }

      return mask & ~n;
    }

    int bitwiseComplementLoop(int N) {
      if (N==0) return 1;
      int shift = 0, res = 0;
      while (N>0) {
        int digit = N & 1;
        res += (1-digit) << shift;

        N >>= 1;
        ++shift;
      }

      return res;
    }
};


int main() {
  Solution sol;

  int N;

  ifstream f("Inputs/1009_ComplementofInteger.txt");
  string line;
  while (getline(f, line)) {
    N = stoi(line);
    cout << sol.bitwiseComplement(N) << endl;
  }

  return 0;
}