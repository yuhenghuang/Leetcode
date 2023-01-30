#include <local_leetcode.hpp>

class Solution {
  private:
    struct Node {
      bool leaf;
      Node* children[26];

      Node(): leaf(false), children{0} { }
    };

  public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
      sort(
        words.begin(), words.end(),
        [] (const string& x, const string& y) {
          return x.size() < y.size();
        }
      );

      Node* root = new Node();

      // whether the substring [0, i) can be concatenated by words 
      bool dp[31];

      vector<string> res;
      for (const string& w : words) {
        memset(dp, false, sizeof(dp));
        dp[0] = true;

        int n = w.size();
        for (int i = 0; i < n; ++i)
          if (dp[i]) {
            Node* node = root;
            for (int j = i; j < n; ++j) {
              node = node->children[w[j] - 'a'];

              if (!node)
                break;
              else if (node->leaf)
                dp[j + 1] = true;
            }

            // early stop
            if (dp[n]) {
              res.push_back(w);
              break;
            }
          }

        // add word to trie
        Node* node = root;
        for (char c : w) {
          int i = c - 'a';

          if (node->children[i] == nullptr)
            node->children[i] = new Node();
          
          node = node->children[i];
        }

        node->leaf = true;
      }

      ll::destroy(root);

      return res;
    }
};


int main() {
  EXECS(Solution::findAllConcatenatedWordsInADict);
  return 0;
}