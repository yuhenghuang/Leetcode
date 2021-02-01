#include "utils2.hpp"
#include <set>
#include <climits>
#include <functional>

class Solution {
  public:
    int minimumDeviation(vector<int>& nums) {
      typedef pair<int, int> pii;
      priority_queue<
        pii,
        vector<pii>,
        function<bool(const pii&, const pii&)>
      > heap(
        [](const pii& lhs, const pii& rhs) -> bool {
          return lhs.first > rhs.first || (lhs.first==rhs.first && lhs.second < rhs.second);
        }
      );

      // max possible value
      int upper = 0;
      for (int num : nums) {
        if (num % 2)
          num *= 2;

        int temp = num;
        while (num % 2 == 0)
          num >>= 1;

        if (num>upper)
          upper = num;
        heap.emplace(num, temp);
      }

      int res = upper - heap.top().first;
      while (heap.top().first < heap.top().second) {
        auto p = heap.top(); heap.pop();

        int temp = p.first * 2;
        if (temp > upper)
          upper = temp;

        heap.emplace(temp, p.second);
        res = min(res, upper - heap.top().first);
      }

      return res;
    }
};


int main() {
  UFUNC(Solution::minimumDeviation);
  return 0;
}