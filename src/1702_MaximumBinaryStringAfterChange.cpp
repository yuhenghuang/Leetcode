#include "utils3.hpp"

class Solution {
  public:
    string maximumBinaryString(string binary) {
      int n = binary.size();

      string res;
      int j = 1;
      for (int i = 0; i < n; ++i) {
        if (binary[i] == '1' || i + 1 == n)
          res.push_back(binary[i]);
        else {
          // try to find first encountered '0' at j
          while (j < n && binary[j] != '0')
            ++j;

          // found '0' at j to pair with '0' at i
          if (j < n) {
            swap(binary[i+1], binary[j]);
            res.push_back('1');
          }
          else
            res.push_back('0');
        }

        ++j;
      }

      return res;
    }
};


int main() {
  UFUNCS(Solution::maximumBinaryString);
  return 0;
}