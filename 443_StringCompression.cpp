#include <local_leetcode.hpp>

class Solution {
  private:
    int compress(vector<char>& chars, int) {
      int j = 1;
      int freq = 1;
      for (int i = 1; i < (int) chars.size(); ++i) {
        if (chars[i] == chars[i-1])
          ++freq;
        else {
          if (freq > 1) {
            const string& num = to_string(freq);
            for (char c : num) 
              chars[j++] = c;
          }

          chars[j++] = chars[i];
          freq = 1;
        }
      }

      if (freq > 1) {
        const string& num = to_string(freq);
        for (char c : num) 
          chars[j++] = c;
      }

      return j;
    }

  public:
    void compress(vector<char>& chars) {
      int n = compress(chars, 0);

      while (chars.size() > n)
        chars.pop_back();
    }
};


int main() {
  EXECS(Solution::compress, void, (vector<char>&));
  return 0;
}