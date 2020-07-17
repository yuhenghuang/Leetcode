#include <cmath>
#include <climits>
#include <iostream>
using namespace std;

class Solution {
public:
    double myPow(double x, long n) {
      if (n==0) return 1;
      long long res = n;
      if (res<0) {
        x = 1/x;
        res = -res;
      }
      double ans = 1;
      long long cur = 1;
      while (cur<=res) {
        ans *= recur(x, cur, res);
        res -= cur;
        cur = 1;
      }
      return ans;
    }

    double recur(double x, long long& cur, long long& res) {
      if ((cur<<1)>res) 
        return x;
      else {
        cur <<= 1;
        return recur(x*x, cur, res);
      }
    }
};

int main() {
  Solution sol;
  cout << sol.myPow(2, -2147483648) << endl;
  long x = -2147483648;
  cout <<(INT_MIN == x) << endl;
  cout << -x << endl;
  return 0;
}