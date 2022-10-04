#include <local_leetcode.hpp>

class Solution {
  private:
    // trie node
    struct Node {
      int count;
      Node* children[26];

      Node(): count(0), children{0} { }
    };

  public:
    vector<int> sumPrefixScores(vector<string>& words) {
      Node* root = new Node();

      for (string& w : words) {
        Node* node = root;
        for (char c : w) {
          int i = c - 'a';
          
          if (node->children[i] == nullptr)
            node->children[i] = new Node();

          node = node->children[i];
          ++node->count;
        }
      }

      vector<int> res;
      for (string& w : words) {
        int count = 0;
        Node* node = root;

        for (char c : w) {
          node = node->children[c - 'a'];
          count += node->count;
        }

        res.push_back(count);
      }

      ll::destroy(root);

      return res;
    }
};


int main() {
  EXECS(Solution::sumPrefixScores);
  return 0;
}