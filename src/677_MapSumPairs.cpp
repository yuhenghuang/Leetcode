#include "utils3.hpp"


struct TrieNode {
  int val;
  unordered_map<char, TrieNode*> children;
  TrieNode(int _val = 0): val(_val) { }

  void insert(const string& s, int v, int i = 0) {
    if (s.size() == i) {
      val = v;
      return;
    }

    char c = s[i];
    if (children.count(c) == 0)
      children[c] = new TrieNode();

    children[c]->insert(s, v, i + 1);
  }

  int query(const string& prefix, int i = 0) {
    if (i < prefix.size()) {
      char c = prefix[i];

      if (children.count(c) == 0)
        return 0;

      return children[c]->query(prefix, i + 1);
    }
    else {
      int sum = val;
      for (auto& p : children)
        sum += p.second->query(prefix, i + 1);
      return sum;
    }
  }
};


class MapSum {
  private:
    TrieNode* root;

  public:
    /** Initialize your data structure here. */
    MapSum() { root = new TrieNode(); }
    
    void insert(string key, int val) {
      root->insert(key, val);
    }
    
    int sum(string prefix) {
      return root->query(prefix);
    }

    ~MapSum() { utils3::destroy(root); }
};


struct Node {
  int val;
  Node* children[26] = {0};
  Node(int _val = 0): val(_val) { }
};


class MapSumFast {
  private:
    Node* root;
    unordered_map<string, int> m;

  public:
    /** Initialize your data structure here. */
    MapSumFast() { root = new Node(); }
    
    void insert(string key, int val) {
      Node* node = root;
      int diff = val - m[key];
      for (char c : key) {
        int i = c - 'a';
        if (node->children[i] == nullptr)
          node->children[i] = new Node();

        node = node->children[i];
        node->val += diff;
      }

      m[key] = val;
    }
    
    int sum(string prefix) {
      Node* node = root;
      for (char c : prefix) {
        node = node->children[c - 'a'];
        if (!node)
          return 0;
      }

      return node->val;
    }

    ~MapSumFast() { utils3::destroy(root); }
};


int main() {
  UFUNCX(
    CTOR(),
    &MapSum::insert,
    &MapSum::sum
  );
  UFUNCX(
    CTOR(),
    &MapSumFast::insert,
    &MapSumFast::sum
  );
  return 0;
}