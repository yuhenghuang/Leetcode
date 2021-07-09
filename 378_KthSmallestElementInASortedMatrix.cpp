#include <functional>
#include "utils2.hpp"


class Solution {
  public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
      typedef vector<int>::iterator iter_type;
      typedef pair<iter_type, iter_type> pii;

      priority_queue<
        pii, 
        vector<pii>,
        std::function<bool (const pii&, const pii&)>
      > heap(
        [](const pii& i, const pii& j) -> bool {
          return *(i.first) > *(j.first);
        }
      );

      for (vector<int>& row : matrix)
        heap.emplace(row.begin(), row.end());


      while (--k) {
        pii p = heap.top();
        heap.pop();

        if (++p.first != p.second)
          heap.emplace(std::move(p));
      }

      return *(heap.top().first);
    }
};


int main() {
  UFUNC(Solution::kthSmallest);
  return 0;
}