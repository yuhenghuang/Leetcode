#include <sstream>
#include <local_leetcode.hpp>

class Solution {
  private:
    struct Node {
      bool leaf;
      Node* children[26];

      Node(): leaf(false), children{0} { }

      Node*& at(char c) {
        return children[c - 'a'];
      }
    };

    void dfs(Node* root, const char* w, string& res) {
      char c = *w++;
      if (nullptr == root || root->leaf || c == '\0') {
        // word not found, thus append all of its remaining characters
        if (nullptr == root && c != '\0') {
          res.push_back(c);
          while (*w != '\0')
            res.push_back(*w++);
        }

        return;
      }

      res.push_back(c);
      dfs(root->at(c), w, res);
    }

  public:
    string replaceWords(vector<string>& dictionary, string sentence) {
      Node* root = new Node();

      for (auto& word : dictionary) {
        Node* node = root;
        for (char c : word) {
          if (node->at(c) == nullptr)
            node->at(c) = new Node();

          node = node->at(c);
        }

        node->leaf = true;
      }

      string res;

      string word;
      istringstream iss(sentence);
      while (getline(iss, word, ' ')) {
        dfs(root, word.c_str(), res);
        res.push_back(' ');
      }

      res.pop_back();

      ll::destroy(root);
      return res;
    }
};


int main() {
  EXECS(Solution::replaceWords);
  return 0;
}