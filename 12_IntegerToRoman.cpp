#include <cmath>
#include "utils2.hpp"

class Solution {
  public:
    string intToRoman(int num) {

      vector<int> vals {1, 5, 10, 50, 100, 500, 1000};
      vector<char> syms {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
      
      string res;
      if (num >= 1000) {
        res += string(num / 1000, 'M');
        num %= 1000;
      }
      
      for (int i=4; i>=0; i-=2) {
        int d = num / static_cast<int>(std::pow(10, i/2));
        num %= static_cast<int>(std::pow(10, i/2));
        
        if (d < 4)
          res += string(d, syms[i]);
        else if (d == 4) {
          res.push_back(syms[i]);
          res.push_back(syms[i+1]);
        }
        else if (d == 5)
          res += syms[i+1];
        else if (d < 9) {
          res += syms[i+1];
          res += string(d-5, syms[i]);
        }
        else {
          res += syms[i];
          res += syms[i+2];
        }

      }
      
      return res;
    }
};


int main() {
  UFUNC(Solution::intToRoman);
  return 0;
}