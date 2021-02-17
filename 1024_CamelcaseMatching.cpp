#include "utils2.hpp"


struct TrieNode {
  int idx;
  unordered_map<char, TrieNode*> children;

  TrieNode(): idx(-1) { }


  void add(int i, const string& s, int idx) {
    if (s.size() == i) {
      this->idx = idx;
      return;
    }

    char c = s[i];
    if (children.count(c) == 0)
      children.emplace(c, new TrieNode());

    children[c]->add(i+1, s, idx);
  }


  void dfs(int i, const string& pat, vector<bool>& res) {
    if (pat.size() == i && idx >= 0)
      res[idx] = true;

    for (auto p : children) {
      if (i < pat.size() && p.first == pat[i])
        p.second->dfs(i+1, pat, res);
      else if (p.first >= 'a')
        p.second->dfs(i, pat, res);
    }
  }
};

class Solution {
  private:
    void dfs(int i, TrieNode* root, const string& pat, vector<bool>& res) {
      int n = pat.size();

      if (i == n && root->idx >= 0) 
        res[root->idx] = true;

      for (auto p : root->children) {
        if (i < n && p.first == pat[i])
          dfs(i+1, p.second, pat, res);
        else if (p.first >= 'a')
          dfs(i, p.second, pat, res);
      }
    }


    bool match(const string& s, const string& p) {
      int m = s.size(), n = p.size();

      int i = 0, j = 0;

      while (i < m) {
        if (j < n && s[i]==p[j]) 
          ++j;
        else if (s[i] < 'a')
          return false;
          
        ++i;
      }

      return i==m && j==n;
    }

  public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
      int n = queries.size();

      TrieNode* root = new TrieNode();
      for (int i=0; i<n; ++i) {
        /*
        TrieNode* node = root;
        for (char c : queries[i]) {
          if (node->children.count(c) == 0)
            node->children[c] = new TrieNode();

          node = node->children[c];
        }

        node->idx = i;
        */
        root->add(0, queries[i], i);
      }

      vector<bool> res(n);
      // dfs(0, root, pattern, res);
      root->dfs(0, pattern, res);
      return res;
    }

    vector<bool> camelMatchGreedy(vector<string>& queries, string pattern) {
      int n = queries.size();

      vector<bool> res;
      res.reserve(n);

      for (const string& s : queries)
        res.push_back(match(s, pattern));

      return res;
    }
};


int main() {
  {
    UFUNC(Solution::camelMatch);
  }
  {
    UFUNC(Solution::camelMatchGreedy);
  }
  return 0;
}