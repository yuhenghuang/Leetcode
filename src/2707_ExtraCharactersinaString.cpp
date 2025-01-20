#include <local_leetcode.hpp>

class Solution {
  private:
    struct Node {
      Node* children[26];
      bool leaf;

      Node(): children{nullptr}, leaf(false) { }
    };


  public:
    int minExtraChar(string s, vector<string>& dictionary) {
      Node* root = new Node();
      for (const string& word : dictionary) {
        Node* node = root;
        for (int i = (int) word.size() - 1; i >= 0; --i) {
          int index = word[i] - 'a';

          if (node->children[index] == nullptr)
            node->children[index] = new Node();

          node = node->children[index];
        }

        node->leaf = true;
      }


      const int n = s.size();
      int dp[51];
      dp[0] = 0;

      for (int i = 0; i < n; ++i) {
        dp[i + 1] = dp[i] + 1;

        Node* node = root;
        for (int j = i; j >= 0; --j) {
          node = node->children[s[j] - 'a'];
          if (node != nullptr) {
            if (node->leaf)
              dp[i+1] = min(dp[i+1], dp[j]);
          }
          else
            break;
        }
      }

      ll::destroy(root);

      return dp[n];
    }
};


int main() {
  EXECS(Solution::minExtraChar);
  return 0;
}