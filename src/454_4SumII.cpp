#include "utils.hpp"
#include <unordered_map>

class Solution {
  private:
    unordered_map<int, int> product(const vector<int>& a, const vector<int>& b) {
      unordered_map<int, int> m;
      for (int i=0; i<a.size(); ++i)
        for (int j=0; j<b.size(); ++j)
          ++m[a[i]+b[j]];

      return m;
    }

  public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
      unordered_map<int, int> m1 = product(A, B);
      unordered_map<int, int> m2 = product(C, D);

      int res = 0;
      for (const auto& p : m1) {
        auto q = m2.find(-p.first);
        if (q!=m2.end())
          res += p.second * q->second;
      }

      return res;
    }
};


int main() {
  UFUNC(Solution::fourSumCount);
  return 0;
}