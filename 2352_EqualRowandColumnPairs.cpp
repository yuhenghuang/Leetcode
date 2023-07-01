#include <local_leetcode.hpp>

class Solution {
  private:
    uint64_t hash(uint64_t seed, int val) const {
      return seed ^ val + 0x9e3779b9 + (seed << 6) + (seed >> 2);
    }

    struct hash_vec {
      std::size_t operator()(std::vector<int> const& vec) const {
        std::size_t seed = vec.size();

        for (uint64_t i : vec)
          seed ^= i + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        
        return seed;
      }
    };

  public:
    int equalPairs(vector<vector<int>>& grid) {
      int n = grid.size();

      // hash_value, row_indcies (in case of hash collision)
      unordered_map<uint64_t, vector<int>> m;

      for (int i = 0; i < n; ++i) {
        uint64_t seed = 0;
        for (int j = 0; j < n; ++j)
          seed = hash(seed, grid[i][j]);

        m[seed].push_back(i);
      }


      int res = 0;
      for (int j = 0; j < n; ++j) {
        uint64_t seed = 0;
        for (int i = 0; i < n; ++i)
          seed = hash(seed, grid[i][j]);

        for (int i : m[seed]) {
          bool flag = true;

          for (int k = 0; k < n; ++k)
            if (grid[k][j] != grid[i][k]) {
              flag = false;
              break;
            }

          if (flag)
            ++res;
        }
      }

      return res;
    }

    int equalPairsHashMap(vector<vector<int>>& grid) {
      const int n = grid.size();

      unordered_map<vector<int>, int, hash_vec> m;
      for (int i = 0; i < n; ++i)
        ++m[grid[i]];

      int res = 0;
      vector<int> vec(n);
      for (int j = 0; j < n; ++j) {
        for (int i = 0; i < n; ++i)
          vec[i] = grid[i][j];

        res += m[vec];
      }

      return res;
    }
};


int main() {
  EXECS(Solution::equalPairs);
  EXECS(Solution::equalPairsHashMap);
  return 0;
}