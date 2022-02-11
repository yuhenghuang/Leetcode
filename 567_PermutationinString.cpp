#include <local_leetcode.hpp>

class Solution {
  private:
    class Letters {
      private:
        short count[26];

      public:
        Letters(const char* first, const char* last): count{0} {
          for (;first != last; ++first)
            add(*first);
        }

        void add(char c) { ++count[c - 'a']; }
        void remove(char c) { --count[c - 'a']; }

        bool operator==(const Letters& rhs) const {
          for (int i = 0; i < 26; ++i)
            if (count[i] != rhs.count[i])
              return false;

          return true;
        }
    };

  public:
    bool checkInclusionOO(string s1, string s2) {
      int m = s1.size();
      int n = s2.size();

      if (m <= n) {
        Letters l1(s1.c_str(), s1.c_str() + m);
        Letters l2(s2.c_str(), s2.c_str() + m);

        if (l1 == l2)
          return true;

        for (int i = m; i < n; ++i) {
          l2.add(s2[i]);
          l2.remove(s2[i-m]);

          if (l1 == l2)
            return true;
        }
      }

      return false;
    }

    bool checkInclusion(string s1, string s2) {
      int n1 = s1.length(), n2 = s2.length();
      if (n1 <= n2) {
        int ans[26] = {0}, cur[26] = {0};
        bool flag;
        for (int i=0; i<n2; ++i) {
          ++cur[s2[i]-'a'];
          if (i<n1) 
            ++ans[s1[i]-'a'];
          else 
            --cur[s2[i-n1]-'a'];

          if (i>n1-2) {
            flag = true;
            for (int j=0; j<26; ++j)
              if (ans[j]!=cur[j]) {
                flag = false;
                break;
              }
            if (flag) return true;
          }
        }
      }
      return false;
    }
};

int main() {
  EXECS(Solution::checkInclusion);
  EXECS(Solution::checkInclusionOO);
  return 0;
}