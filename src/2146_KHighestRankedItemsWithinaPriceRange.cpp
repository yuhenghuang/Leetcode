#include <local_leetcode.hpp>

class Solution {
  private:
    struct Item {
      // distance, price, row, col
      int data[4];

      template <
        typename... Ints,
        typename = typename std::enable_if<
          std::conjunction<std::is_same<Ints, int> ...>::value
        >::type,
        typename = typename std::enable_if<sizeof...(Ints) == 4>::type
      >
      Item(const Ints&... ls): data{ls...} {}

      const int& operator[](size_t i) const { return data[i]; }

      bool operator<(const Item& rhs) const {
        return lexicographical_compare(
          begin(data), end(data), 
          begin(rhs.data), end(rhs.data)
        );
      }

      bool operator>(const Item& rhs) const {
        return !(*this < rhs);
      }
    };

  public:
    vector<vector<int>> highestRankedKItems(const vector<vector<int>>& grid, 
                                            const vector<int>& pricing, 
                                            const vector<int>& start, 
                                            int k) 
    {
      int m = grid.size();
      int n = grid[0].size();

      int dirs[4][2] {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};

      queue<pair<int, int>> q;
      q.emplace(start[0], start[1]);

      vector<vector<bool>> seen(m, vector<bool>(n));
      seen[start[0]][start[1]] = true;

      priority_queue<Item, vector<Item>, greater<Item>> heap;

      int dist = 0;
      while (!q.empty()) {
        int s = q.size();
        while (s--) {
          auto [r, c] = q.front();
          q.pop();

          int price = grid[r][c];
          if (pricing[0] <= price && price <= pricing[1])
            heap.emplace(dist, price, r, c);

          for (auto& dir : dirs) {
            int i = r + dir[0];
            int j = c + dir[1];
            if (i >= 0 && i < m && j >= 0 && j < n && grid[i][j] && !seen[i][j]) {
              seen[i][j] = true;
              q.emplace(i, j);
            }
          }
        }

        ++dist;
      }

      vector<vector<int>> res;
      while (!heap.empty() && k--) {
        const Item& item = heap.top();

        res.push_back({item[2], item[3]});

        heap.pop();
      }

      return res;
    }
};


int main() {
  EXECS(Solution::highestRankedKItems);
  return 0;
}