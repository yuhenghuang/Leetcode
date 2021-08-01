#include "utils3.hpp"

class Solution {
  private:
    int n;
    vector<int>& blacklist;
    vector<int> whitelist;

  public:
    Solution(int _n, vector<int>& _blacklist): n(_n), blacklist(_blacklist) {
      sort(blacklist.begin(), blacklist.end());

      if (n < blacklist.size() + 100000) {
        whitelist.reserve(n - blacklist.size());

        int j = 0;
        for (int i = 0; i < n; ++i) {
          if (j < blacklist.size() && i == blacklist[j])
            ++j;
          else
            whitelist.push_back(i);
        }
      }

    }
    
    int pick() {
      if (n < blacklist.size() + 100000)
        return whitelist[rand() % whitelist.size()];
      else {
        int num;
        vector<int>::iterator iter;
        do {
          num = rand() % n;
          iter = lower_bound(blacklist.begin(), blacklist.end(), num);
        } while (iter != blacklist.end() && *iter == num);

        return num;
      }
    }
};


class SolutionITV {
  private:
    vector<int> indices;
    vector<pair<int, int>> intervals;

  public:
    SolutionITV(int n, vector<int>& blacklist) {
      sort(blacklist.begin(), blacklist.end());

      blacklist.push_back(n);
      indices.push_back(0);

      int l = 0;
      for (int r : blacklist) {
        if (l != r) {
          intervals.emplace_back(l, r);
          indices.push_back(indices.back() + r - l);
        }
        l = r + 1;
      }
    }
    
    int pick() {
      int i = upper_bound(indices.begin() ,indices.end(), rand() % indices.back()) - indices.begin() - 1;
      auto& p = intervals[i];
      return p.first + rand() % (p.second - p.first);
    }
};


int main() {
  UFUNCX(
    CTOR(int, vector<int>&),
    &Solution::pick
  );
  UFUNCX(
    CTOR(int, vector<int>&),
    &SolutionITV::pick
  );
  return 0;
}