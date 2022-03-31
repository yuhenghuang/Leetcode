#include <local_leetcode.hpp>

class Solution {
  private:
    struct Index {
      int sum;
      int moves;
      vector<int> indicies;

      Index(): sum(0), moves(0) { };
      Index(const Index&) = default;
      Index(Index&& rhs) noexcept : sum(rhs.sum), indicies(std::move(rhs.indicies)) { }

      Index& operator=(const Index&) = default;

      bool operator==(const Index& rhs) const {
        return sum == rhs.sum && indicies == rhs.indicies;
      }

      bool operator>(const Index& rhs) const {
        return sum > rhs.sum;
      }
    };

  public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
      // wrong answer...

      int m = mat.size();
      int n = mat[0].size();

      vector<vector<int>> dp(k);

      priority_queue<Index, vector<Index>, greater<Index>> heap;

      Index index;
      index.indicies.assign(m, 0);

      for (int i = 0; i < m; ++i)
        index.sum += mat[i][0];

      heap.push(std::move(index));

      while (true) {
        index = heap.top();

        if (k == 0)
          return index.sum;

        ++index.moves;
        heap.pop();

        for (int i = 0; i < m; ++i)
          if (index.indicies[i] + 1 < n) {
            Index next = index;
            next.sum += mat[i][next.indicies[i] + 1] - mat[i][next.indicies[i]];
            ++next.indicies[i];

            heap.push(std::move(next));
          }
      }

      return -1;
    }
};


int main() {
  EXECS(Solution::kthSmallest);
  return 0;
}