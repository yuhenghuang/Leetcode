#include <local_leetcode.hpp>

class Solution {
  private:
    typedef pair<int, int> ii_t;

  public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
      vector<ii_t> engineers;
      engineers.reserve(n);
      for (int i = 0; i < n; ++i)
        engineers.emplace_back(efficiency[i], speed[i]);

      sort(engineers.begin(), engineers.end(), greater<ii_t>());

      long sum = 0;
      long res = 0;
      priority_queue<int, vector<int>, greater<int>> heap;

      int i = 0;
      for (; i < k; ++i) {
        ii_t& p = engineers[i];
        heap.push(p.second);
        sum += p.second;

        res = max(res, sum * p.first);
      }
      for (; i < n; ++i) {
        ii_t& p = engineers[i];
        if (heap.top() < p.second) {
          sum += p.second - heap.top();
          heap.pop();
          heap.push(p.second);

          res = max(res, sum * p.first);
        }
      }

      return res % long(1e9 + 7);
    }

    int maxPerformanceNew(int n, vector<int>& speed, vector<int>& efficiency, int k) {
      // (speed, efficiency)
      vector<ii_t> engineers(n);

      transform(
        speed.begin(), speed.end(), 
        efficiency.begin(), 
        engineers.begin(),
        [](const int& s, const int& e) -> ii_t { return {s, e}; }
      );

      // sort by efficiency
      sort(
        engineers.begin(), engineers.end(),
        [] (const ii_t& x, const ii_t& y) {
          return x.second > y.second;
        }
      );


      // min heap of speed
      priority_queue<int, vector<int>, greater<int>> heap;

      int64_t sum = 0; // sum of speed
      int64_t res = 0;

      for (int i = 0; i < n; ++i) {
        auto& [s, e] = engineers[i];

        if (i < k) {
          sum += s;

          heap.push(s);

          res = max(res, sum * e);
        }
        else if (heap.top() < s) {
          sum += s - heap.top();

          heap.pop();
          heap.push(s);

          res = max(res, sum * e);
        }
      }

      return res % int(1e9 + 7);
    }
};


int main() {
  EXECS(Solution::maxPerformance);
  EXECS(Solution::maxPerformanceNew);
  return 0;
}
