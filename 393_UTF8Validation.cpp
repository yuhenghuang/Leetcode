#include <local_leetcode.hpp>

class Solution {
  public:
    bool validUtf8(vector<int>& data) {
      int n = data.size();

      int i = 0;

      while (i < n) {
        const int& byte = data[i];
        if (byte == 255)
          return false;
        else if (((byte >> 7) & 1) == 0) {
          // 1-byte character, do nothing
          ++i;
        }
        else if (((byte >> 6) & 1) == 0)
          return false;
        else {
          // count leading ones
          int j = 2;
          while ((byte >> (7 - j)) & 1)
            ++j;

          // at most 4 bytes
          if (j > 4)
            return false;

          // data[i] >> 6 -> two bits
          // must be 0x10, aka 2
          for (++i, --j; i < n && j > 0; ++i, --j)
            if ((data[i] >> 6) != 2)
              return false;

          if (j > 0)
            return false;
        }
      }

      return true;
    }
};


int main() {
  EXECS(Solution::validUtf8);
  return 0;
}
