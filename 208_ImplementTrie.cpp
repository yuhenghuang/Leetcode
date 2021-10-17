#include "utils3.hpp"

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


class Trie {
  private:
    TrieNode* root;

  public:
    /** Initialize your data structure here. */
    Trie() {
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

    ~Trie() { utils3::destroy(root); }
};

int main() {
  UFUNCX(
    CTOR(),
    &Trie::insert,
    &Trie::search,
    &Trie::startsWith
  );
  return 0;
}