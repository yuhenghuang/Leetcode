#include <complex>
#include "utils3.hpp"

// complex number with integer real and image part
class ComplexNumber {
  private:
    int r, i;

  public:
    ComplexNumber(int _r, int _i): r(_r), i(_i) { }

    ComplexNumber(string s) {
      sscanf(s.c_str(), "%d+%di", &r, &i);
    }

    ComplexNumber operator*(const ComplexNumber& x) {
      return ComplexNumber(
        r * x.r - i * x.i,
        r * x.i + i * x.r
      );
    }

    string toString() {
      return to_string(r) + '+' + to_string(i) + 'i';
    }
};


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

    string complexNumberMultiplyUser(string a, string b) {
      return (ComplexNumber(a) * ComplexNumber(b)).toString();
    }
};


int main() {
  UFUNCS(Solution::complexNumberMultiply);
  UFUNCS(Solution::complexNumberMultiplyUser);
  return 0;
}