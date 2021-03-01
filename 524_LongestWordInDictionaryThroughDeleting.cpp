#include "utils2.hpp"


struct TrieNode {
  int idx, len;
  unordered_map<char, TrieNode*> children;

  TrieNode(): idx(-1), len(-1) { }

  void add(int idx, const string& s, int i = 0) {
    if (s.size() == i) {
      this->idx = idx;
      this->len = s.size();
      return;
    }

    char c = s[i];
    if (children.count(c) == 0)
      children[c] = new TrieNode();

    children[c]->add(idx, s, i+1);
  }


  void query(int& res, int& l, const string& s, int i = 0) {
    if (s.size() == i) {
      if (len > l || (len == l && idx < res)) {
        l = len;
        res = idx;
      }
      return;
    }

    query(res, l, s, i+1);

    for (auto p : children)
      if (p.first == s[i])
        p.second->query(res, l, s, i+1);
  }
};


class Solution {
  private:
    bool isSubstr(const string& x, const string& y) {
      if (x.size() < y.size())
        return false;

      int j = 0;
      for (int i=0 ; i<x.size() && j<y.size(); ++i)
        if (x[i] == y[j])
          ++j;

      return j == y.size();
    }

  public:
    string findLongestWord(string s, vector<string>& d) {
      string res;

      for (const string& w : d) {
        if (isSubstr(s, w)) {
          if (w.length() > res.length() || (w.length() == res.length() && w < res))
            res = w;
        }
      }

      return res;
    }

    string findLongestWordTLE(string s, vector<string>& d) {
      sort(d.begin(), d.end());

      TrieNode* root = new TrieNode();
      for (int i=0; i<d.size(); ++i)
        root->add(i, d[i]);

      int res = INT_MAX, l = 0;
      root->query(res, l, s);

      return l > 0 ? d[res] : "";
    }
};


int main() {
  UFUNC(Solution::findLongestWord);
  return 0;
}