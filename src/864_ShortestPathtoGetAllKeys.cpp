#include <local_leetcode.hpp>

class Solution {
  private:
    template<char... cs>
    bool in(char t) {
      for (char c : {cs...})
        if (t == c)
          return true;

      return false;
    }

  public:
    int shortestPathAllKeys(vector<string>& grid) {
      typedef tuple<int8_t, int8_t, int8_t> i3_t;

      constexpr int dirs[4][2] {{0,1}, {1,0}, {-1,0}, {0, -1}};

      const int m = grid.size();
      const int n = grid[0].size();

      bool seen[64][31][31]; // bits of keys，row, column

      int r = 0; // # of key and lock

      queue<i3_t> q; // bits of keys，row, column

      unordered_map<char, int> char2index; // update keys and locks to start from 'a' or 'A'

      for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j) {
          char c = grid[i][j];
          if (c == '@')
            q.emplace(0, i, j);
          else if (!in<'.', '#'>(c) && c >= 'a')
            char2index[c] = r++;
        }

      const int target = (1 << r) - 1;

      memset(seen, 0, (1 << r) * sizeof(bool[31][31]));
      seen[0][get<1>(q.front())][get<2>(q.front())] = true;

      for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j) {
          char c = grid[i][j];
          if (!in<'.', '#', '@'>(c))
            // update keys and locks
            grid[i][j] = (c >= 'a') ? ('a' + char2index[c]) : ('A' + char2index[c + 32]);
        }

      int res = 1;
      while (!q.empty()) {
        int N = q.size();
        while (N--) {
          auto [k, i, j] = q.front();
          q.pop();

          for (auto& d :dirs) {
            int r = i + d[0];
            int c = j + d[1];

            if (0 <= r && r < m && 0 <= c && c < n && grid[r][c] != '#') {
              char ch = grid[r][c];

              // new key
              int kk = ch >= 'a' ? (k | (1 << (ch -'a'))) : k;

              if (kk == target)
                return res;

              // empty cell or key cell or have key to unlock
              if (in<'.', '@'>(ch) || ch >= 'a' || (kk & (1 << (ch - 'A')))) {
                if (!seen[kk][r][c]) {
                  seen[kk][r][c] = true;
                  q.emplace(kk, r, c);
                }              
              }
            }
          }
        }
        ++res;
      }

      return -1;
    }
};


int main() {
  EXECS(Solution::shortestPathAllKeys);
  return 0;
}