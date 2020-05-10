#include <iostream>
using namespace std;

class Solution {
  public:
    int findComplement(int num) {
      int shift = 0, res = 0;
      do {
        res += (1 - (1 & num)) << shift;
        num >= 1;
        ++shift;
      } while (num>0);
      return res;
    }
};

int main() {
  Solution sol;
  cout << sol.findComplement(1) << endl;
  return 0;
}