#define _LL_PRINT_ARRAY_MAX_LENGTH 100
#include <local_leetcode.hpp>

#define MAX_LEVEL 17

class Trie {
  private:
    struct Node {
      int count;
      Node* left; // bit 1
      Node* right; // bit 0

      // lazy initialization
      Node(): count(0), left(nullptr), right(nullptr) { }

      bool hasLeft() { return left && left->count > 0; }
      bool hasRight() { return right && right->count > 0; }

      Node* getLeft() {
        if (nullptr == left)
          left = new Node();

        return left;
      }

      Node* getRight() {
        if (nullptr == right)
          right = new Node();

        return right;
      }
    };

    Node* root;

    void addImpl(Node* node, int val, int level) {
      ++node->count;

      if (level == -1)
        return;

      addImpl(
        ((val >> level) & 1) ? node->getLeft() : node->getRight(),
        val, level - 1
      );
    }

    void removeImpl(Node* node, int val, int level) {
      --node->count;

      if (level == -1)
        return;

      removeImpl(
        ((val >> level) & 1) ? node->getLeft() : node->getRight(),
        val, level - 1
      );
    }

    int queryImpl(Node* node, int val, int level) {
      if (level == -1)
        return 0;
      // only right leaf
      else if (!node->hasLeft())
        return (val & (1 << level)) | queryImpl(node->getRight(), val, level - 1);
      // only left leaf
      else if (!node->hasRight())
        return ((val ^ (1 << level)) & (1 << level)) | queryImpl(node->getLeft(), val, level - 1);
      else 
        return (1 << level) | queryImpl(((val >> level) & 1) ? node->getRight() : node->getLeft(), val, level - 1);
    }

  public:
    Trie(): root(new Node()) { }

    // add value
    void add(int val) { addImpl(root, val, MAX_LEVEL); }

    // remove value
    void remove(int val) { removeImpl(root, val, MAX_LEVEL); }

    // query maximum of val & (values in trie)
    int query(int val) { return queryImpl(root, val, MAX_LEVEL); }

    ~Trie() { ll::destroy(root); }
};

class Solution {
  private:
    struct Node {
      int val;
      vector<Node*> children;

      Node(int _val): val(_val) { }
    };

    void dfs(int root, Trie& trie, const vector<vector<int>>& tree, const vector<vector<int>>& indicies, const vector<vector<int>>& queries, vector<int>& res) {
      trie.add(root);

      for (const int& i : indicies[root])
        res[i] = trie.query(queries[i][1]);

      for (const int& child : tree[root])
        dfs(child, trie, tree,indicies, queries, res);

      trie.remove(root);
    }

    void dfs(Node* root, Trie& trie, const vector<vector<int>>& indicies, const vector<vector<int>>& queries, vector<int>& res) {
      trie.add(root->val);

      for (const int& i : indicies[root->val])
        res[i] = trie.query(queries[i][1]);

      for (auto& child : root->children)
        dfs(child, trie, indicies, queries, res);

      trie.remove(root->val);
    }

  public:
    vector<int> maxGeneticDifference(vector<int>& parents, vector<vector<int>>& queries) {
      int n = parents.size();

      Node* root;
      vector<Node*> nodes;
      nodes.reserve(n);

      for (int i = 0; i < n; ++i) 
        nodes.push_back(new Node(i));

      for (int i = 0; i < n; ++i)
        if (parents[i] >= 0)
          nodes[parents[i]]->children.push_back(nodes[i]);
        else
          root = nodes[i];

      vector<vector<int>> indicies(n);

      for (int i = 0; i < queries.size(); ++i)
        indicies[queries[i][0]].push_back(i);

      Trie trie;
      vector<int> res(queries.size());

      dfs(root, trie, indicies, queries, res);

      ll::destroy(root);

      return res;
    }

    // partial procedure-oriented solution
    vector<int> maxGeneticDifferencePO(vector<int>& parents, vector<vector<int>>& queries) {
      int n = parents.size();

      int root;
      vector<vector<int>> tree(n);

      for (int i = 0; i < n; ++i)
        if (parents[i] >= 0)
          tree[parents[i]].push_back(i);
        else
          root = i;

      vector<vector<int>> indicies(n);

      for (int i = 0; i < queries.size(); ++i)
        indicies[queries[i][0]].push_back(i);

      Trie trie;
      vector<int> res(queries.size());

      dfs(root, trie, tree, indicies, queries, res);

      return res;
    }

    vector<int> maxGeneticDifferenceTLE(vector<int>& parents, vector<vector<int>>& queries) {
      vector<int> res;
      res.reserve(queries.size());

      for (auto& query : queries) {
        int p = query[0];
        int val = query[1];
        
        int diff = p ^ val;

        while (parents[p] >= 0) {
          p = parents[p];
          diff = max(diff, p ^ val);
        }

        res.push_back(diff);
      }

      return res;
    }
};


int main() {
  EXECS(Solution::maxGeneticDifference);
  EXECS(Solution::maxGeneticDifferencePO);
  EXECS(Solution::maxGeneticDifferenceTLE);
  return 0;
}