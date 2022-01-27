#include <local_leetcode.hpp>

struct TrieNode {
  bool deletion;
  size_t hash_val;

  // use map instead of unordered_map to maintain the order of subfolders
  // such that we can compare subfolders of two folder in linear time
  map<string, TrieNode*> children;

  TrieNode(): deletion(false), hash_val(0) { }

  bool operator!=(const TrieNode& rhs) const { return !(*this == rhs); }

  bool operator==(const TrieNode& rhs) const {
    if (children.size() != rhs.children.size())
      return false;

    auto iter = rhs.children.begin();
    for (auto& p : children) {
      // name or the contents of the subfolders not matched
      if (p.first != iter->first || *p.second != *(iter->second))
        return false;
      ++iter;
    }
    return true;
  }
};

class Solution {
  private:
    size_t hashTrieNodes(TrieNode* root, unordered_map<size_t, vector<TrieNode*>>& m) {
      if (root->children.empty())
        return 0;

      for (auto& [folder, node] : root->children) 
        root->hash_val += hash<string>()(folder) + hashTrieNodes(node, m);

      m[root->hash_val].push_back(root);

      return root->hash_val;
    }

    void labelDeletion(TrieNode* root, unordered_map<size_t, vector<TrieNode*>>& m) {
      if (root->deletion || root->children.empty())
        return;

      bool flag = false; // whether to delete root
      vector<TrieNode*>& vec = m[root->hash_val];
      auto iter = vec.begin();

      // try to skip redundant comparisons because the comparison is expensive

      // skip compared pairs
      while (*iter != root)
        ++iter;

      for (++iter; iter != vec.end(); ++iter)
        // skip deleted folders
        if (!(*iter)->deletion && *root == **iter) {
          flag = true;
          (*iter)->deletion = true;
        }

      if (flag)
        root->deletion = true;
      else // proceed only if root is not to be deleted
        for (auto& p : root->children)
          labelDeletion(p.second, m);
    }

    void restorePaths(TrieNode* root, vector<string>& s, vector<vector<string>>& res) {
      for (auto& [folder, node] : root->children) 
        if (!node->deletion) {
          s.push_back(folder);
          res.push_back(s);

          restorePaths(node, s, res);

          s.pop_back();
        }
    }

  public:
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
      TrieNode* root = new TrieNode();
      for (auto& path : paths) {
        TrieNode* node = root;

        for (auto& folder : path) {
          if (node->children.count(folder) == 0)
            node->children[folder] = new TrieNode();

          node = node->children[folder];
        }

        // node->leaf = true;
      }

      // hash value, nodes
      unordered_map<size_t, vector<TrieNode*>> m;
      hashTrieNodes(root, m);

      labelDeletion(root, m);

      vector<string> s;
      vector<vector<string>> res;
      restorePaths(root, s, res);

      ll::destroy(root);

      return res;
    }
};


int main() {
  EXECS(Solution::deleteDuplicateFolder);
  return 0;
}