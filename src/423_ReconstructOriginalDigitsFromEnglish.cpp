#include "utils2.hpp"

class Solution {
  public:
    string originalDigits(string s) {
      int count[26] = {0};
      for (char c : s)
        ++count[c-'a'];
      
      vector<int> digits(10);
      
      digits[0] = count['z'-'a'];
      digits[2] = count['w'-'a'];
      digits[4] = count['u'-'a'];
      digits[8] = count['g'-'a'];
      
      digits[3] = count['t'-'a'] - digits[2] - digits[8];
      digits[1] = count['o'-'a'] - digits[0] - digits[2] - digits[4];
      
      digits[5] = count['f'-'a'] - digits[4];
      digits[7] = count['v'-'a'] - digits[5];
      digits[6] = count['s'-'a'] - digits[7];
      digits[9] = count['i'-'a'] - digits[5] - digits[6] - digits[8];
      
      string res;
      for (int i=0; i<10; ++i)
        res += string(digits[i], (char)('0' + i));
      
      return res;
    }
};


int main() {
  UFUNC(Solution::originalDigits);
  return 0;
}