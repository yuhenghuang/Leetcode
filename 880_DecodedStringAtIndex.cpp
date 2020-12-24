#include "utils.hpp"

class Solution {
  private:
    char res;

    void recursion(int idx, int left, int& k, const string& s) {
      int i = idx;
      while (i<s.length() && isalpha(s[i]))
        ++i;

      int right = i-idx;

      int repeat = i < s.length() ? (s[i++]-'0') : 1;

      long len = (left+right)*static_cast<long>(repeat);
      if (k>len) 
        recursion(i, len, k, s);

      if (k<=len) {
        int rem = (k-1) % (left+right) + 1;

        if (rem>left) 
          res = s[idx+rem-left-1];
        else 
          k = rem;
      }
    }

  public:
    string decodeAtIndex(string S, int K) {
      recursion(0, 0, K, S);
      return {res};
    }
};


int main() {
  UFUNC(Solution::decodeAtIndex);
  return 0;
}