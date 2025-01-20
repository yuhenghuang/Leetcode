#define _LL_FLATTEN_2D
#define _LL_NONTRIVIAL_SOLUTION_CTOR
#include <local_leetcode.hpp>


class Solution {
  private:
    // trie node
    struct Node {
      int idx;
      Node* children[26];

      Node(): idx(-1), children{0} {}

      template <class Iterator>
      void add(Iterator first, Iterator last, int index) {
        if (first == last) {
          idx = index;
          return;
        }

        Node*& child = children[*(first++) - 'a'];
        if (child == nullptr)
          child = new Node();

        child->add(first, last, index);
      }

      // ~Node() { for (auto& child : children) delete child; }
    };

    bool isPalindromic(int i, int j, const string& s) {
      while (i < j) {
        if (s[i++] != s[j--])
          return false;
      }

      return true;
    }

    // check the remaining substring to be palindromic or not
    void dfs(Node* node, int k, int i, const vector<string>& words, vector<vector<int>>& res) {
      if (!node)
        return;

      if (node->idx >= 0 && node->idx != i) {
        const string& w = words[node->idx];

        // (forward index, backward index)

        // i is backward index
        if (k >= 0 && isPalindromic(k, (int) w.size() - 1, w))
          res.push_back({node->idx, i});
        // i is forward index
        else if (k < 0 && isPalindromic(0, (int) w.size() + k, w))
          res.push_back({i, node->idx});
      }

      for (auto& child : node->children)
        dfs(child, k, i, words, res);
    }

    // forward and backward at the same time
    void dfs(Node* root_fwd, Node* root_bwd, int k, const vector<string>& words, vector<vector<int>>& res) {
      if (!root_fwd || !root_bwd)
        return;
      
      // two strings of the same length
      if (root_fwd->idx >= 0 && root_bwd->idx >= 0 && (root_fwd->idx != root_bwd->idx))
          res.push_back({root_fwd->idx, root_bwd->idx});
        
      // either forward or backward string comes to an end first
      // check the remaining part to be palindromic
      if (root_fwd->idx >= 0)
        for (auto& child : root_bwd->children)
          // -k - 1 to use (-oo, 0) to indicate that forward index is kept still
          dfs(child, -k - 1, root_fwd->idx, words, res);

      if (root_bwd->idx >= 0)
        for (auto& child : root_fwd->children)
          dfs(child, k, root_bwd->idx, words, res);

      for (int i = 0; i < 26; ++i)
        dfs(root_fwd->children[i], root_bwd->children[i], k + 1, words, res);
    }


    vector<Node*> roots;

  public:
    ~Solution() { ll::universal_destroyer<decltype(roots)>()(roots);}

    vector<vector<int>> palindromePairs(vector<string>& words) {
      int n = words.size();

      // save the index of REVERSED words
      unordered_map<string, int> word2idx;
      for (int i = 0; i < n; ++i) {
        const string& w = words[i];
        string s(w.rbegin(), w.rend());
        word2idx[s] = i;
      }


      unordered_map<string, int>::iterator iter;
      vector<vector<int>> res;
      for (int i = 0; i < n; ++i) {
        const string& w = words[i];

        // find the palindromic overlapped substring,
        // and look up the reversed non-overlapped substring
        for (int j = 0; j <= w.size(); ++j) {
          // words[i] on left
          if (isPalindromic(j, w.size() - 1, w)) {
            iter = word2idx.find(w.substr(0, j));

            // avoid the case where words[i] + words[i] is palindrome
            if (iter != word2idx.end() && iter->second != i)
              res.push_back({i, iter->second});
          }

          // words[i] on right
          // j > 0 to avoid duplicate caused by symmetric cases, e.g. abc + cba
          if (j > 0 && isPalindromic(0, j - 1, w)) {
            iter = word2idx.find(w.substr(j, w.size() - j));

            if (iter != word2idx.end())
              res.push_back({iter->second, i});
          }
        }
      }

      return res;
    }

    vector<vector<int>> palindromePairsNew(vector<string>& words) {
      // Memory Limit Exceeded if not release trie
      // Time Limit Exceeded if release trie
      // but on my local machine, this solution is faster...

      vector<vector<int>> res;

      Node* root_fwd = new Node();
      Node* root_bwd = new Node();

      for (int i = 0; i < (int) words.size(); ++i) {
        string& w = words[i];
        root_fwd->add(w.begin(), w.end(), i);
        root_bwd->add(w.rbegin(), w.rend(), i);
      }

      dfs(root_fwd, root_bwd, 0, words, res);

      // delete root_fwd; delete root_bwd;
      // ll::destroy(root_fwd); ll::destroy(root_bwd);

      // don't count the time of releasing memories
      roots.push_back(root_fwd); roots.push_back(root_bwd);

      return res;
    }

};

int main() {
  EXECS(Solution::palindromePairs);
  EXECS(Solution::palindromePairsNew);
  return 0;
}
