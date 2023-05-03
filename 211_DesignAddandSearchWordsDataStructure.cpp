/*
#include <vector>
#include <string>
#include <iostream>
#include <iterator>
using namespace std;
*/

#include <local_leetcode.hpp>

class TrieNode {
  public:
    TrieNode* children[26]={0};
    bool leaf;
    TrieNode(): leaf(false) {};

    TrieNode* findAdd(char c) {
      if (children[c - 'a']==nullptr)
        children[c - 'a'] = new TrieNode();
      return children[c - 'a'];
    }

    TrieNode* find(char c) {
      return children[c - 'a'];
    }
};

class WordDictionary {
  private:
    TrieNode* root;

    bool search_impl(TrieNode* node, int idx, const string& s) {
      if (node==nullptr)
        return false;
      if (idx==s.length())
        return node->leaf;

      bool flag = false;
      char c = s[idx];
      if (c!='.')
        flag = search_impl(node->find(c), idx+1, s);
      else {
        for (int i=0; i<26; ++i)
          if (node->children[i]!=nullptr) {
            flag = search_impl(node->children[i], idx+1, s);
            if (flag) break;
          }
      }
      return flag;
    }

    bool search_impl(TrieNode* node, const char* w) {
      if (!node)
        return false;
      if (*w == '\0')
        return node->leaf;

      bool flag = false;
      
      char c = *w++;
      if (c != '.')
        flag = search_impl(node->find(c), w);
      else 
        for (int i = 0; i < 26; ++i)
          if (node->children[i] != nullptr) {
            flag = search_impl(node->children[i], w);
            if (flag) 
              break;
          }

      return flag;
    }
  public:
    /** Initialize your data structure here. */
    WordDictionary() {
      root = new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
      TrieNode *node = root;
      for (char c : word) 
        node = node->findAdd(c);
      node->leaf = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
      // return search_impl(root, 0, word);
      return search_impl(root, word.c_str());
    }

    ~WordDictionary() { ll::destroy(root); }
};

int main() {
  /*
  WordDictionary obj;
  obj.addWord("bad");
  obj.addWord("dad");
  obj.addWord("mad");
  vector<bool> res;
  res.push_back(obj.search("pad"));
  res.push_back(obj.search("bad"));
  res.push_back(obj.search(".ad"));
  res.push_back(obj.search("b.."));

  copy(res.begin(), res.end(), ostream_iterator<bool>(cout, " "));
  */

  EXECX(
    CTOR(),
    &WordDictionary::addWord,
    &WordDictionary::search
  );

  return 0;
}