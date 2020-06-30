#include <vector>
#include <string>
#include <iterator>
#include <iostream>
using namespace std;

class TrieNode {
  private:
    TrieNode* dict[26]={0};
  public:
    int idx;

    TrieNode(): idx(-1) {}

    TrieNode* findOrAdd(char c) {
      if (!dict[c-'a'])
        dict[c-'a'] = new TrieNode();
      return dict[c-'a'];
    }

    TrieNode* find(char c) {
      return dict[c-'a'];
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
      seen = vector<vector<bool>>(m, vector<bool>(n, false));

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
  vector<vector<char>> board = {
    {'o','a','a','n'},
    {'e','t','a','e'},
    {'i','h','k','r'},
    {'i','f','l','v'}
  };

  vector<string> words = {"oath","pea","eat","rain"};

  Solution sol;
  vector<string> res = sol.findWords(board, words);
  copy(res.begin(), res.end(), ostream_iterator<string>(cout, " "));
  return 0;
}