#include "utils2.hpp"

class Solution {
  private:
    static bool Compare(const string& x, const string& y) {
      int n = min(x.size(), y.size());
      for (int i = 0; i < n; ++i) {
        if (x[i] < y[i])
          return true;
        else if (x[i] > y[i])
          return false;
      }

      return x.size() < y.size();
    }

  public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
      sort(products.begin(), products.end(), Compare);

      int n = searchWord.size();
      vector<vector<string>> res(n);
      for (int i = 0; i < n; ++i) {
        string prefix = searchWord.substr(0, i+1);

        auto bg = lower_bound(products.begin(), products.end(), prefix, Compare);
        for (int j = 0; j < 3; ++j, ++bg) {
          if (bg == products.end() || bg->size() <= i || bg->substr(0, i+1) != prefix) break;
          res[i].push_back(*bg);
        }
      }

      return res;
    }
};


int main() {
  UFUNC(Solution::suggestedProducts);
  return 0;
}