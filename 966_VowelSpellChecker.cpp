#include <unordered_set>
#include "utils2.hpp"

class Solution {
  private:
    unordered_set<string> wordsSet;
    unordered_map<string, string> low2Words;
    unordered_map<string, string> vow2Words;
  
    string toLower(const string& s) {
      string out;
      for (char c : s)
        out.push_back(::tolower(c));
      
      return out;
    }
  
    string deVowel(const string& s) {
      string out;
      for (char c : s)
        out.push_back(
          (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') ? '*' : c
        );
      
      return out;
    }
  
    string match(const string& s) {
      if (wordsSet.count(s))
        return s;
      
      string tmp;
      tmp = toLower(s);
      if (low2Words.count(tmp))
        return low2Words[tmp];
      
      tmp = deVowel(tmp);
      if (vow2Words.count(tmp))
        return vow2Words[tmp];
      
      return "";
    }
  
  public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
      for (const string& w : wordlist) {
        wordsSet.insert(w);
        
        low2Words.emplace(toLower(w), w);
        vow2Words.emplace(deVowel(toLower(w)), w);
      }
      
      vector<string> res;
      res.reserve(queries.size());
      
      for (const string& q : queries) 
        res.push_back(match(q));
      
      return res;
    }
};

int main() {
  UFUNC(Solution::spellchecker);
  return 0;
}