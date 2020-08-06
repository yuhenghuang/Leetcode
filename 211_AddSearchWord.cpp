#include <vector>
#include <string>
#include <iostream>
#include <iterator>
using namespace std;

class TrieNode {
  public:
    TrieNode* dict[26]={0};
    bool leaf;
    TrieNode(): leaf(false) {};

    TrieNode* findAdd(char c) {
      if (dict[c-'a']==nullptr)
        dict[c-'a'] = new TrieNode();
      return dict[c-'a'];
    }
    TrieNode* find(char c) {
      return dict[c-'a'];
    }
};

class WordDictionary {
  private:
    TrieNode *root;
    bool search(TrieNode *node, int idx, string &s) {
      if (node==nullptr)
        return false;
      if (idx==s.length())
        return node->leaf;

      bool flag = false;
      char c = s.at(idx);
      if (c!='.')
        flag = search(node->find(c), idx+1, s);
      else {
        for (int i=0; i<26; ++i)
          if (node->dict[i]!=nullptr) {
            flag = search(node->dict[i], idx+1, s);
            if (flag) break;
          }
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
      return search(root, 0, word);
    }
};

int main() {
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
  return 0;
}