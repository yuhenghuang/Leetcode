#include <list>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

int factoral(int n) {
  if (n<2) 
    return 1;
  else
    return n * factoral(n-1);
}

class Solution {
  public:
    string getPermutation(int n, int k) {
      list<int> l;
      for (int i=1; i<=n; ++i)
        l.push_back(i);

      stringstream ss;
      --k;
      while (n--) {
        int mod = factoral(n);
        int idx = k / mod ;
        k %= mod;
        auto iter = l.begin();
        while (idx--)
          ++iter;

        ss << *iter;
        l.erase(iter);
      }
      return ss.str();
    }
};

int main() {
  Solution sol;
  cout << sol.getPermutation(4, 9) << endl;
  return 0;
}