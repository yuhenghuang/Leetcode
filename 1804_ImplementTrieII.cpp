#include "utils3.hpp"

class Trie {
  private:
    struct Node {
      int pass;
      int end;
      unordered_map<char, Node*> children;

      Node(): pass(0), end(0) { }
    };

    Node* root;

    void append(Node* node, const char* w) {
      char c = *w++;
      if (c == '\0') {
        ++node->end;
        return;
      }

      Node* child;
      if (node->children.count(c) == 0)
        child = node->children[c] = new Node();
      else
        child = node->children[c];

      ++child->pass;
      append(child, w);
    }


    void remove(Node* node, const char* w) {
      char c = *w++;
      if (c == '\0') {
        --node->end;
        return;
      }

      // w is always valid
      Node* child = node->children[c];

      --child->pass;
      remove(child, w);
    }

    int countequal(Node* node, const char* w) {
      char c = *w++;
      if (c == '\0') 
        return node->end;

      auto iter = node->children.find(c);

      if (iter != node->children.end() && iter->second->pass > 0)
        return countequal(iter->second, w);
      else
        return 0;
    }

    int countstartwith(Node* node, const char* w) {
      char c = *w++;
      if (c == '\0') 
        return node->pass;

      auto iter = node->children.find(c);

      if (iter != node->children.end() && iter->second->pass > 0)
        return countstartwith(iter->second, w);
      else
        return 0;
    }

  public:
    Trie() {
      root = new Node();
    }

    void insert(string word) {
      append(root, word.c_str());
    }

    int countWordsEqualTo(string word) {
      return countequal(root, word.c_str());
    }

    int countWordsStartingWith(string prefix) {
      return countstartwith(root, prefix.c_str());
    }

    void erase(string word) {
      return remove(root, word.c_str());
    }

    // ~Trie() { utils3::destroy(root); }
};


int main() {
  UFUNCX(
    CTOR(),
    &Trie::insert,
    &Trie::countWordsEqualTo,
    &Trie::countWordsStartingWith,
    &Trie::erase
  );
  return 0;
}