#include <local_leetcode.hpp>

class Solution {
  private:
    template <class Iterator>
    bool equal_range(Iterator first1, Iterator first2, int n) {
      for (; n > 0; --n)
        if (*first1++ != *first2++)
          return false;

      return true;
    }

    template <class Iterator>
    bool any(Iterator first1, vector<Iterator>& vec_first2, int n) {
      for (auto& first2 : vec_first2)
        if (equal_range(first1, first2, n))
          return true;

      return false;
    }

  public:
    int longestCommonSubpath(int _n, vector<vector<int>>& paths) {
      // size of paths
      int m = paths.size();

      // size of shortest path
      int n = min_element(
        paths.begin(), 
        paths.end(),
        [](const vector<int>& x, const vector<int>& y) -> bool {
          return x.size() < y.size();
        }
      )->size();

      int l = 1, r = n;
      while (l <= r) {
        int mid = l + (r - l) / 2;
      }

      return r;
    }

    int longestCommonSubpathTLE(int _n, vector<vector<int>>& paths) {
      int n = paths.size();

      // size of shortest path
      int m = min_element(
        paths.begin(), 
        paths.end(),
        [](const vector<int>& x, const vector<int>& y) -> bool {
          return x.size() < y.size();
        }
      )->size();


      constexpr size_t k = 7;
      constexpr size_t mod = 1e10 + 7;

      vector<size_t> multipliers(m);

      multipliers[0] = 1;
      for (int i = 1; i < m; ++i)
        multipliers[i] = (multipliers[i-1] * k) % mod;

      int l = 1, r = m;
      while (l <= r) {
        int length = l + (r - l) / 2;

        unordered_map<size_t, vector<vector<int>::iterator>> prev;

        int j = 0;
        size_t hash_val = 0;
        vector<int>& path = paths.front();

        for (; j < length; ++j)
          hash_val = (hash_val + path[j] * multipliers[length - 1 - j]) % mod;

        prev[hash_val].push_back(path.begin());

        for (; j < path.size(); ++j) {
          hash_val = ((hash_val - (path[j - length] * multipliers[length - 1]) % mod + mod) * k + path[j]) % mod;

          prev[hash_val].push_back(path.begin() + j - length + 1);
        }

        bool flag = true;
        unordered_map<size_t, vector<vector<int>::iterator>> curr;
        unordered_map<size_t, vector<vector<int>::iterator>>::iterator iter;

        for (int i = 1; i < n; ++i) {
          j = 0;
          hash_val = 0;

          vector<int>& path = paths[i];

          for (; j < length; ++j)
            hash_val = (hash_val + path[j] * multipliers[length - 1 - j]) % mod;

          iter = prev.find(hash_val);
          if (iter != prev.end() && any(path.begin(), iter->second, length))
            curr[hash_val].push_back(path.begin());

          for (; j < path.size(); ++j) {
            hash_val = ((hash_val - (path[j - length] * multipliers[length - 1]) % mod + mod) * k + path[j]) % mod;

            iter = prev.find(hash_val);
            if (iter != prev.end() && any(path.begin() + j - length + 1, iter->second, length))
              curr[hash_val].push_back(path.begin() + j - length + 1);
          }

          if (curr.empty()) {
            flag = false;
            break;
          }

          swap(prev, curr);
          curr.clear();
        }

        if (flag)
          l = length + 1;
        else
          r = length - 1;
      }

      return r;
    }
};


int main() {
  EXECS(Solution::longestCommonSubpathTLE);
  return 0;
}