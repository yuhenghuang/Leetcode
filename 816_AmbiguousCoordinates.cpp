#include "utils2.hpp"

class Solution {
  private:
    void enumerate(const string& s, vector<string>& vec) {
      int n = s.size();

      if (n == 1)
        vec.push_back(s);
      else {
        if (s[0] == '0') {
          if (s[n-1] != '0')
            vec.push_back("0." + s.substr(1, n-1));
        }
        else {
          vec.push_back(s);

          if (s[n-1] != '0')
            for (int i = 1; i < n; ++i)
              vec.push_back(s.substr(0, i) + '.' + s.substr(i, n - i));
        }
      }
    }

  public:
    vector<string> ambiguousCoordinates(string s) {
      int n = s.size();

      vector<string> res, ls, rs;
      for (int i = 1; i < n - 2; ++i) {
        ls.clear();
        rs.clear();
        enumerate(s.substr(1, i), ls);
        enumerate(s.substr(i+1, n-i-2), rs);

        for (string& l : ls)
          for (string& r : rs)
            res.push_back('(' + l + ", " + r + ')');
      }

      return res;
    }
};


int main() {
  UFUNC(Solution::ambiguousCoordinates);
  return 0;
}