#include <vector>
#include <cmath>
#include <iostream>
#include <iterator>

using namespace std;

class Solution {
  private:
    vector<int> res;
  public:
    vector<int> numsSameConsecDiff(int N, int K) {
      for (int i=1; i<10; ++i)
        dfs(i, N-1, K);

      if (N==1)
        res.push_back(0);
      return res;
    }

    void dfs(int cur, int N, int &K) {
      if (N==0) {
        res.push_back(cur);
        return;
      }

      int rem = cur % 10;
      cur *= 10;
      if (rem+K<10) dfs(cur+rem+K, N-1, K);
      if (K>0 && rem-K>=0) dfs(cur+rem-K, N-1, K);
    }
};

int main() {
  Solution sol;
  vector<int> res = sol.numsSameConsecDiff(1, 0);
  copy(res.begin(), res.end(), ostream_iterator<int>(cout, " "));
  return 0;
}