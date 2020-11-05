#include "utils.hpp"
#include <complex>

class Solution {
  private:
    complex<int> convert2complex(string& s) {
      size_t delim = s.find_first_of('+');
      return complex<int>(stoi(s.substr(0, delim)), stoi(s.substr(delim+1)));
    }
  public:
    string complexNumberMultiply(string a, string b) {

      // alternative unpack, more concise
      int a1, a2, b1, b2;
      sscanf(a.c_str(), "%d+%di", &a1, &a2);
      sscanf(b.c_str(), "%d+%di", &b1, &b2);

      complex<int> x = convert2complex(a), y = convert2complex(b), z = x * y;
      char buffer[50];
      sprintf(buffer, "%d+%di", z.real(), z.imag());
      return string(buffer);
    }
};


int main() {
  UFUNC(Solution::complexNumberMultiply);
  return 0;
}