#include "utils3.hpp"

class Solution {
  private:
    bool compareTail(string& s, string& p) {
      if (s.size() < p.size())
        return false;

      // early stop
      for (int i = 0; i < p.size(); ++i)
        if (s[s.size() - i - 1] != p[p.size() - i - 1])
          return false;

      return true;
    }

  public:
    string removeOccurrences(string s, string part) {
      string res;
      for (char c : s) {
        res.push_back(c);

        if (compareTail(res, part)) 
          for (int i = 0; i < part.size(); ++i)
            res.pop_back();
      }

      return res;
    }
};


int main() {
  UFUNCS(Solution::removeOccurrences);
  return 0;
}