#include "utils3.hpp"

class Solution {
  private:
    int word2Int(string& w) {
      int i = 0;
      for (char c : w)
        i |= 1 << (c - 'a');

      return i;
    }

  public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
      unordered_map<int, int> m;
      for (string& w : words)
        ++m[word2Int(w)];

      int n = puzzles.size();

      vector<int> res(n);
      for (int i = 0; i < n; ++i) {
        string& p = puzzles[i];

        // loop over combinations of puzzles
        for (int j = 0; j < (1 << 6); ++j) {
          int mask = 1 << (p[0] - 'a');
          for (int k = 0; k < 6; ++k)
            if ((j >> k) & 1 > 0) 
              mask |= 1 << (p[k+1] - 'a');

          res[i] += m[mask];
        }
      }

      return res;
    }
};


int main() {
  UFUNCS(Solution::findNumOfValidWords);
  return 0;
}