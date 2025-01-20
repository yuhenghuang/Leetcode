#include <local_leetcode.hpp>

class Solution {
  public:
    bool checkIfPangram(string sentence) {
      // int bits = 0;
      // for (char c : sentence)
      //   bits |= 1 << (c - 'a');

      int bits = accumulate(sentence.begin(), sentence.end(), 0, [](int i, char c) { return i | (1 << (c - 'a')); });

      return bits == (1 << 26) - 1;
    }
};


int main() {
  EXECS(Solution::checkIfPangram);
  return 0;
}