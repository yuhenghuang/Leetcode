#include <local_leetcode.hpp>

class Solution {
  private:
    class Anagram {
      private:
        short _m_count[26];
      
      public:
        Anagram(): _m_count{0} { }

        Anagram(const char* w, int n): _m_count{0} {
          for (int i = 0; i < n; ++i)
            ++_m_count[*w++ - 'a'];
        }

        void add(char c) { ++_m_count[c - 'a']; }

        void remove(char c) { --_m_count[c - 'a']; }

        bool operator==(const Anagram& rhs) const {
          for (int i = 0; i < 26; ++i)
            if (_m_count[i] != rhs._m_count[i])
              return false;

          return true;
        }
    };

  public:
    vector<int> findAnagrams(string s, string p) {
      int n = s.size();
      int m = p.size();

      if (n < m)
        return {};

      Anagram anagram_s(s.c_str(), m);
      const Anagram anagram_p(p.c_str(), m);

      vector<int> res;

      if (anagram_s == anagram_p)
        res.push_back(0);

      for (int i = m; i < n; ++i) {
        anagram_s.add(s[i]);
        anagram_s.remove(s[i - m]);

        if (anagram_s == anagram_p)
          res.push_back(i - m + 1);
      }
      
      return res;
    }
};


int main() {
  EXECS(Solution::findAnagrams);
  return 0;
}