#include <local_leetcode.hpp>

class Solution {
  private:
    // is x a subset of y
    bool isSubset(vector<int>& x, vector<int>& y) {
      if (x.front() > y.back() || x.back() < y.front())
        return false;

      size_t i = 0, j = 0;
      while (i < x.size() && j < y.size()) {
        if (x[i] == y[j])
          ++i;

        ++j;
      }

      return i == x.size();
    }

  public:
    vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
      int n = favoriteCompanies.size();

      unordered_map<string, int> str2int;
      vector<int> lists[n];

      int uid = 0;
      for (int i = 0; i < n; ++i) {
        vector<int>& ls = lists[i];
        ls.reserve(favoriteCompanies[i].size());
        for (string& s : favoriteCompanies[i]) {
          auto iter = str2int.find(s);
          if (iter == str2int.end()) {
            ls.push_back(uid);
            str2int[s] = uid++;
          }
          else
            ls.push_back(iter->second);
        }

        sort(ls.begin(), ls.end());
      }

      vector<int> indicies(n);
      iota(indicies.begin(), indicies.end(), 0);

      sort(
        indicies.begin(),
        indicies.end(),
        [&favoriteCompanies](const int& i, const int& j) -> bool {
          return favoriteCompanies[i].size() > favoriteCompanies[j].size();
        }
      );

      vector<int> res;
      for (int i = 0; i < n; ++i) {
        vector<int>& ls = lists[indicies[i]];

        bool flag = false;
        for (int j = 0; lists[indicies[j]].size() > ls.size(); ++j)
          if (isSubset(ls, lists[indicies[j]])) {
            flag = true;
            break;
          }

        if (!flag)
          res.push_back(indicies[i]);
      }

      sort(res.begin(), res.end());
      return res;
    }

    vector<int> peopleIndexesFast(vector<vector<string>>& favoriteCompanies) {
      unordered_map<string, bitset<100>> m;
      for (int i = 0; i < favoriteCompanies.size(); ++i) {
        bitset<100> b;
        b.set(i);
        for (string& f : favoriteCompanies[i])
          m[f] |= b;
      }

      vector<int> res;
      for (int i = 0; i < favoriteCompanies.size(); ++i) {
        bitset<100> b;
        b.flip();
        for (string& f : favoriteCompanies[i])
          b &= m[f];

        // i is the only person who has all the companies in favoriteCompanies[i]
        if (b.count() == 1)
          res.push_back(i);
      }

      return res;
    }
};


int main() {
  EXECS(Solution::peopleIndexes);
  EXECS(Solution::peopleIndexesFast);
  return 0;
}