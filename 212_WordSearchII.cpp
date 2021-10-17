#define _NONTRIVIAL_SOLUTION_CTOR
#include "utils3.hpp"

struct TrieNode {
    TrieNode* children[26]={0};
    int idx;

    TrieNode(): idx(-1) {}

    TrieNode* findOrAdd(char c) {
      if (!children[c-'a'])
        children[c-'a'] = new TrieNode();
      return children[c-'a'];
    }

    TrieNode* find(char c) {
      return children[c-'a'];
    }
};

class Solution {
  private:
    int m, n;
    int dir_row[4] = {1, -1, 0, 0};
    int dir_clm[4] = {0, 0, 1, -1};
    vector<string> res;
    vector<vector<bool>> seen;
  public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
      m = board.size();
      n = board[0].size();
      seen.assign(m, vector<bool>(n, false));
      res.clear();

      TrieNode* root = new TrieNode();
      for (int i=0; i<words.size(); ++i) {
        TrieNode* node = root;
        for (char c : words[i])
          node = node->findOrAdd(c);
        node->idx = i;
      }

      for (int i=0; i<m; ++i)
        for (int j=0; j<n; ++j)
          dfs(root, i, j, board, words);

      utils3::destroy(root);
      return res;
    }

    void dfs(TrieNode* node, int i, int j, vector<vector<char>>& board, vector<string>& words) {
      if (i<0 || i>=m || j<0 || j>=n || seen[i][j]) return;

      TrieNode* next = node->find(board[i][j]);
      if (!next) return;

      seen[i][j] = true;

      if (next->idx!=-1) {
        res.push_back(words[next->idx]);
        next->idx=-1;
      }

      for (int k=0; k<4; ++k)
        dfs(next, i+dir_row[k], j+dir_clm[k], board, words);
      
      seen[i][j] = false;
    }
};

int main() {
  UFUNCS(Solution::findWords);
  return 0;
}