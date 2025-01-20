#include "utils.hpp"
#include <utility>

struct TrieNode {
  TrieNode* next[26] = {0};
  int idx;
  TrieNode(): idx(-1) { }
};

class Solution {
  private:
    void pushIndex(TrieNode* node, bool* seen, queue<int>& q, string s, int idx, int aster) {
      if (aster>1)
        return;

      if (idx==s.size()) {
        if (aster==1 && !seen[node->idx]) {
          q.push(node->idx);
          seen[node->idx] = true;
          // node->idx = -1;
        }
      }
      else {
        for (int i=0; i<26; ++i) 
          if (node->next[i])
            pushIndex(node->next[i], seen, q, s, idx+1, aster + ((s[idx]-'a')!=i));
      }
    }

    int findIndex(TrieNode* node, string s, int idx) {
      if (idx==s.size())
        return node->idx;

      int i = s[idx] - 'a';
      return node->next[i] ? findIndex(node->next[i], s, idx+1) : -1;
    }

  public:
    int ladderLengthBiDir(string beginWord, string endWord, vector<string>& wordList) {
      int n = wordList.size();

      TrieNode* root = new TrieNode();
      TrieNode* node;
      for (int i=0; i<n; ++i) {
        node = root;
        for (char c : wordList[i]) {
          if (node->next[c-'a']==nullptr)
            node->next[c-'a'] = new TrieNode();

          node = node->next[c-'a'];
        }

        node->idx = i;
      }

      int target = findIndex(root, endWord, 0);
      if (target<0)
        return 0;

      wordList.push_back(beginWord);

      queue<int> q1, q2;
      q1.push(n);
      q2.push(target);

      bool* s1 = new bool[n+1];
      bool* s2 = new bool[n+1];
      memset(s1, 0, n+1);
      memset(s2, 0, n+1);
      s1[n] = true;
      s2[target] = true;

      int res=1;
      while (!q1.empty() && !q2.empty()) {
        if (q1.size()>q2.size()) {
          swap(q1, q2);
          swap(s1, s2);
        }

        int N = q1.size();
        while (N--) {
          int v = q1.front(); q1.pop();
          if (s2[v]) {
            wordList.pop_back();
            return res;
          }

          pushIndex(root, s1, q1, wordList[v], 0, 0);
        }

        ++res;
      }

      wordList.pop_back();
      return 0;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
      int n = wordList.size();

      TrieNode* root = new TrieNode();
      TrieNode* node;
      for (int i=0; i<n; ++i) {
        node = root;
        for (char c : wordList[i]) {
          if (node->next[c-'a']==nullptr)
            node->next[c-'a'] = new TrieNode();

          node = node->next[c-'a'];
        }

        node->idx = i;
      }

      int target = findIndex(root, endWord, 0);
      if (target<0)
        return 0;

      wordList.push_back(beginWord);

      queue<int> q;
      q.push(n);

      bool seen[n];
      memset(seen, 0, n);

      int res = 1;
      while (!q.empty()) {
        int N = q.size();
        while (N--) {
          int v = q.front(); q.pop();
          if (v==target)
            return res;

          pushIndex(root, seen, q, wordList[v], 0, 0);
        }

        ++res;
      }

      return 0;
    }
};


int main() {
  {
    UFUNC(Solution::ladderLength);
  }
  {
    UFUNC(Solution::ladderLengthBiDir);
  }
  return 0;
}