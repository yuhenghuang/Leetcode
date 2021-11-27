#include "utils3.hpp"

class Solution {
  private:
    template <class Comparator>
    const char* maxValueImpl(const char* d, int x, Comparator comp, string& res) {
      while (*d != '\0') {
        // find first digit by proper comparator
        if (comp(x, *d-'0')) {
          res.push_back(char('0' + x));
          return d;
        }
        else
          res.push_back(*d++);
      }

      // if no such digit, append x and the end
      if (*d == '\0')
        res.push_back(char('0' + x));

      return d;
    }

  public:
    string maxValue(string n, int x) {
      string res;

      const char* d = n.c_str();
      if (*d == '-') {
        res.push_back('-');
        d = maxValueImpl(++d, x, less<int>(), res);
      }
      else
        d = maxValueImpl(d, x, greater<int>(), res);

      // append remaining digits
      while (*d != '\0')
        res.push_back(*d++);

      return res;
    }
};


int main() {
  UFUNCS(Solution::maxValue);
  return 0;
}