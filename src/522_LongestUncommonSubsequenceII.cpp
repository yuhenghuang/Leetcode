#include <unordered_set>
#include "utils3.hpp"

class Solution {
  private:
    void encode(vector<unordered_set<long>>& vec, const string& str) {
      int n = str.size();
      vec.resize(n + 1);

      for (int i = 0; i < (1 << n); ++i) {
        int l = 0;
        long temp = 0;
        for (int j = 0; j < n; ++j)
          if ((i >> j) & 1) {
            ++l;
            temp = (temp << 5) ^ (str[j] - 'a');
          }

        vec[l].insert(temp);
      }
    }

    bool predicate(vector<vector<unordered_set<int>>>& comb, int l) {
      for (int i = 0; i < comb.size(); ++i)
        for (int e : comb[i][l])
          for (int j = i + 1; j < comb.size(); ++j)
            if (comb[j][l].count(e))
              return false;

      return true;
    }

  public:
    int findLUSlength(vector<string>& strs) {
      int n = strs.size();
      vector<vector<unordered_set<long>>> comb(n);

      for (int i = 0; i < n; ++i)
        encode(comb[i], strs[i]);

      for (int l = 10; l >= 0; --l) {
        for (int i = 0; i < n; ++i)
          if (comb[i].size() > l)
            for (long e : comb[i][l]) {
              bool flag = true;

              for (int j = 0; j < n; ++j)
                if (j != i && comb[j].size() > l && comb[j][l].count(e)) {
                  flag = false;
                  break;
                }

              if (flag)
                return l;
            }
      }

      return -1;
    }
};


int main() {
  UFUNCS(Solution::findLUSlength);
  return 0;
}