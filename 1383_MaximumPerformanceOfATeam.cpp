#include "utils2.hpp"

class Solution {
  private:
    typedef pair<int, int> pii;

  public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
      vector<pii> engineers;
      engineers.reserve(n);
      for (int i = 0; i < n; ++i)
        engineers.emplace_back(efficiency[i], speed[i]);

      sort(engineers.begin(), engineers.end(), greater<pii>());

      long sum = 0;
      long res = 0;
      priority_queue<int, vector<int>, greater<int>> heap;

      int i = 0;
      for (; i < k; ++i) {
        pii& p = engineers[i];
        heap.push(p.second);
        sum += p.second;

        res = max(res, sum * p.first);
      }
      for (; i < n; ++i) {
        pii& p = engineers[i];
        if (heap.top() < p.second) {
          sum += p.second - heap.top();
          heap.pop();
          heap.push(p.second);

          res = max(res, sum * p.first);
        }
      }

      return res % long(1e9 + 7);
    }
};


int main() {
  UFUNC(Solution::maxPerformance);
  return 0;
}