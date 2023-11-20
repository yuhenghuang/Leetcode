#include<local_leetcode.hpp>

class Solution {
  private:
    int kthGrammarImpl(int n, int k) {
      if (n == 0)
        return 0;

      return kthGrammarImpl(n - 1, k >> 1) ^ (k & 1);
    }

  public:
    int kthGrammar(int &N, int &K) {
      if (N==1 && K==1) return 0;
      int r = (K+1) % 2;
      K = (K+1)/2;
      N--;
      return kthGrammar(N, K) ^ r;
    }

    int kthGrammarNew(int n, int k) {
      return kthGrammarImpl(n - 1, k - 1);
    }
};

int main() {
  // Solution sol;
  // int n = 29, k = 12;
  // cout << sol.kthGrammar(n, k) << endl;

  EXECS(Solution::kthGrammar);
  EXECS(Solution::kthGrammarNew);
}
