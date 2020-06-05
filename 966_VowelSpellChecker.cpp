#include <vector>
#include <string>
#include <iterator>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

class TrieNode {
  private:
    vector<TrieNode*> dict;
  public:
    bool flag;
    TrieNode(): flag(false) {dict.resize(58);}

    TrieNode* find(char c) {
      return dict[c-'A'];
    }

    TrieNode* findOrAdd(char c) {
      if (!dict[c-'A'])
        dict[c-'A'] = new TrieNode();
      return dict[c-'A'];
    }
};

class Solution {
  private:
    TrieNode* root;
    stringstream ss;
    string temp;
    char vowels[10] = {'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};
    // size_t ten = 10 * sizeof(char);
  public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
      root = new TrieNode();
      for (string& s : wordlist) {
        TrieNode* node = root;
        for (char c : s) 
          node = node->findOrAdd(c);
        node->flag = true;
      }
      
      int n = queries.size();
      vector<string> res(n);
      for (int i=0; i<n; ++i) {
        ss.clear();
        res[i] = dfs(root, 0, queries[i]) ? temp.substr(temp.length()-queries[i].length(), temp.length()) : "";
      }
      return res;
    }

    bool dfs(TrieNode* node, int idx, string& s) {
      if (idx==s.length()) {
        if (node->flag) {
          temp = ss.str();
          return true;
        }
        else return false;
      }
      char c = s[idx];
      TrieNode* next = node->find(c);
      if (next) {
        ss << c;
        if (dfs(next, idx+1, s)) return true; 
        // ss >> c;
      }

      c = c>'Z' ? c-32 : c+32;
      next = node->find(c);
      if (next) {
        ss << c;
        if (dfs(next, idx+1, s)) return true; 
        // ss >> c;
      }

      if (find(vowels, vowels+10, c)!=(vowels+10))
        for (char d : vowels)
          if (d != c) {
            next = node->find(d);
            if (next) {
              ss << d;
              if (dfs(next, idx+1, s)) return true; 
              // ss >> d;
            }
          }
      return false;
    }
};

int main() {
  Solution sol;
  vector<string> wordlist = {"KiTe","kite","hare","Hare"};
  vector<string> queries = {"kite","Kite","KiTe","Hare","HARE","Hear","hear","keti","keet","keto"};
  vector<string> res = sol.spellchecker(wordlist, queries);
  copy(res.begin(), res.end(), ostream_iterator<string>(cout, ", "));
  return 0;
}