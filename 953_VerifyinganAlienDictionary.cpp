#include <local_leetcode.hpp>

class Solution {
  private:
    bool compareWords(string& x, string& y) {
      size_t n = min(x.size(), y.size());
      for (size_t i=0; i<n; ++i)
        if (x[i] < y[i])
          return true;
        else if (x[i] > y[i])
          return false;
      
      return x.size() <= y.size();
    }

    bool compareWords(string& x, string& y, int al2en[26]) {
      size_t n = min(x.size(), y.size());
      for (size_t i=0; i<n; ++i)
        if (al2en[x[i] - 'a'] < al2en[y[i] - 'a'])
          return true;
        else if (al2en[x[i] - 'a'] > al2en[y[i] - 'a'])
          return false;
      
      return x.size() <= y.size();
    }
  
  public:
    bool isAlienSorted(vector<string>& words, string order) {
      int al2en[26];
      for (int i=0; i<26; ++i)
        al2en[order[i] - 'a'] = i;

      for (int i=1; i<words.size(); ++i)
        if (!compareWords(words[i-1], words[i], al2en))
          return false;
        
      return true;
    }

    bool isAlienSortedSlow(vector<string>& words, string order) {
      unordered_map<char, char> al2en;
      for (int i=0; i<26; ++i)
        al2en[order[i]] = 'a' + i;
      
      for (string& w : words)
        for (char& c : w)
          c = al2en[c];
      
      for (int i=1; i<words.size(); ++i)
        if (!compareWords(words[i-1], words[i]))
          return false;
        
      return true;
    }
};


int main() {
  EXECS(Solution::isAlienSorted);
  EXECS(Solution::isAlienSortedSlow);
  return 0;
}