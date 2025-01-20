#include "utils2.hpp"

struct TrieNode {
  unordered_map<char, TrieNode*> children;
  
  void add(const string& s, int i) {
    if (i < 0)
      return;
    
    char c = s[i];
    if (children.count(c) == 0)
      children.emplace(c, new TrieNode());
    
    children[c]->add(s, i-1);
  }
  
  
  int search(int len) {
    if (children.size() == 0)
      return len + 1;

    int res = 0;
    for (auto p : children)
      res += p.second->search(len + 1);

    return res;
  }
};


class Solution {
  private:
    int sharps, lengths;
  
    void search(TrieNode* root, int len) {
      if (root->children.size() == 0) {
        lengths += len;
        ++sharps;
        return;
      }
      
      for (auto p : root->children)
        search(p.second, len + 1);
    }
  
  public:
    int minimumLengthEncoding(vector<string>& words) {
      TrieNode* root = new TrieNode();
      
      for (const string& w : words)
        root->add(w, w.size() - 1);
      
      /*
      sharps = 0;
      lengths = 0;
    
      search(root, 0);
      return lengths + sharps;
      */

      return root->search(0);
    }
};


int main() {
  UFUNC(Solution::minimumLengthEncoding);
  return 0;
}