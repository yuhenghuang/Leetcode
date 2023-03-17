#include <local_leetcode.hpp>

struct TrieNode {
  unordered_map<char, TrieNode*> children;
  bool flag = false;

  TrieNode() { }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
      if (word.length()>0) {
        auto iter = children.find(word[0]);
        TrieNode* p;
        if (iter==children.end()) {
          p = new TrieNode();
          children.insert(make_pair(word[0], p));
        }
        else
          p = iter->second;
        p->insert(word.substr(1, word.length()));
      }
      else
        flag = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
      if (word.length()>0) {
        auto iter = children.find(word[0]);
        return iter==children.end() ? false : iter->second->search(word.substr(1, word.length()));
      }
      else
        return flag;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
      if (prefix.length()>0) {
        auto iter = children.find(prefix[0]);
        return iter==children.end() ? false : iter->second->startsWith(prefix.substr(1, prefix.length()));
      }
      else
        return true;
    }
};


class TrieOld {
  private:
    TrieNode* root;

  public:
    /** Initialize your data structure here. */
    TrieOld() {
      root = new TrieNode();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
      root->insert(word);
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
      return root->search(word);
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
      return root->startsWith(prefix);
    }

    ~TrieOld() { ll::destroy(root); }
};


class Trie {
  private:
    struct Node {
      Node* children[26];
      bool leaf;

      Node(): children{0}, leaf(false) { }
    };

    Node* root;

  public:
    Trie(): root(new Node()) { }

    
    
    void insert(string word) {
      Node* node = root;
      for (char c : word) {
        int i = c - 'a';
        if (node->children[i] == nullptr)
          node->children[i] = new Node();

        node = node->children[i];
      }

      node->leaf = true;
    }
    
    bool search(string word) {
      Node* node = root;
      for (char c : word) {
        node = node->children[c - 'a'];

        if (!node)
          return false;
      }

      return node->leaf;
    }
    
    bool startsWith(string prefix) {
      Node* node = root;
      for (char c : prefix) {
        node = node->children[c - 'a'];

        if (!node)
          return false;
      }

      return true;
    }
    
    ~Trie() { ll::destroy(root); }
};


int main() {
  EXECX(
    CTOR(),
    &TrieOld::insert,
    &TrieOld::search,
    &TrieOld::startsWith
  );

  EXECX(
    CTOR(),
    &Trie::insert,
    &Trie::search,
    &Trie::startsWith
  );
  return 0;
}