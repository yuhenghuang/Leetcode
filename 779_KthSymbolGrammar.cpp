#include <iostream>
using namespace std;

class Solution {
  public:
    int kthGrammar(int &N, int &K) {
      if (N==1 && K==1) return 0;
      int r = (K+1) % 2;
      K = (K+1)/2;
      N--;
      return kthGrammar(N, K) ^ r;
    }
};

int main() {
  Solution sol;
  int n = 29, k = 12;
  cout << sol.kthGrammar(n, k) << endl;
}