#include <local_leetcode.hpp>

#define N 10

class Solution {
  private:
    static vector<string> hs[];

    static bool helper;
    static bool init() {
      hs[1] = {"a", "b", "c"};

      for (int n = 2; n <= N; ++n) 
        for (char c : {'a', 'b', 'c'})
          for (const string& s : hs[n-1])
            if (c != s.front())
              hs[n].emplace_back(c + s);

      return true;
    }

  public:
    string getHappyString(int n, int k) {
      return k <= hs[n].size() ? hs[n][k-1] : "";
    }

    string getHappyStringO1(int n, int k) {
      string res;

      if ((k > (3 * (1 << (n - 1)))))
        return "";
      else if (k <= (1 << (n - 1)))
        res.push_back('a');
      else if (k <= (1 << n)) {
        res.push_back('b');
        k -= (1 << (n - 1));
      }
      else {
        res.push_back('c');
        k -= (1 << n);
      }

      int i = 2;
      for (; i <= n; ++i) {
        if (k <= (1 << (n - i)))
          res.push_back(res.back() != 'a' ? 'a' : 'b');
        else {
          res.push_back(res.back() != 'c' ? 'c' : 'b');
          k -= (1 << (n - i));
        }
      }

      return res;
    }
};

vector<string> Solution::hs[N+1];
bool Solution::helper = Solution::init();


int main() {
  EXECS(Solution::getHappyString);
  EXECS(Solution::getHappyStringO1);
  return 0;
}