#include <local_leetcode.hpp>

class Solution {
  private:
    struct Node {
      bool leaf;
      Node* children[26];

      Node(): leaf(false), children{0} { }
    };

    void dfs(Node* root, string& s, string& res) {
      if (s.size() > res.size())
        res = s;

      for (int i = 0; i < 26; ++i) 
        if (root->children[i] && root->children[i]->leaf) {
          s.push_back('a' + i);

          dfs(root->children[i], s, res);

          s.pop_back();
        }
    }

  public:
    string longestWord(vector<string>& words) {
      Node* root = new Node();

      for (auto& w : words) {
        Node* node = root;

        for (char c : w) {
          if (!node->children[c - 'a'])
            node->children[c - 'a'] = new Node();

          node = node->children[c - 'a'];
        }

        node->leaf = true;
      }

      string s;
      string res;
      dfs(root, s, res);

      ll::destroy(root);

      return res;
    }
};


int main() {
  EXECS(Solution::longestWord);
  return 0;
}