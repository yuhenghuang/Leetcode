#include <local_leetcode.hpp>

class Solution {
  private:
    // substring i <= substring j
    bool compare(const string& s, int i, int j) {
      int n = s.size();
      for (int k = 0; k < n; ++k) {
        if (s[i] < s[j])
          return true;
        else if (s[i] > s[j])
          return false;

        i = (i + 1) % n;
        j = (j + 1) % n;
      }

      // substring i == substring j
      return true;
    }

  public:
    string orderlyQueue(string s, int k) {
      if (k > 1) {
        sort(s.begin(), s.end());
        return s;
      }

      int i = 0;
      for (int j = 1; j < (int) s.size(); ++j)
        if (!compare(s, i, j))
          i = j;

      string res(s.begin() + i, s.end());
      copy(s.begin(), s.begin() + i, back_inserter(res));

      return res;
    }
};


int main() {
  EXECS(Solution::orderlyQueue);
  return 0;
}