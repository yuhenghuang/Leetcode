#include <unordered_map>
#include <iostream>
using namespace std;

class Trie {
  private:
    unordered_map<char, Trie*> dict;
    bool flag = false;
  public:
    /** Initialize your data structure here. */
    Trie() {
      
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
      if (word.length()>0) {
        auto iter = dict.find(word[0]);
        Trie* p;
        if (iter==dict.end()) {
          p = new Trie();
          dict.insert(make_pair(word[0], p));
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
        auto iter = dict.find(word[0]);
        return iter==dict.end() ? false : iter->second->search(word.substr(1, word.length()));
      }
      else
        return flag;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
      if (prefix.length()>0) {
        auto iter = dict.find(prefix[0]);
        return iter==dict.end() ? false : iter->second->startsWith(prefix.substr(1, prefix.length()));
      }
      else
        return true;
    }
};

int main() {
  Trie trie;
  trie.insert("apple");
  cout << trie.search("apple") << endl;
  cout << trie.search("app") << endl;
  cout << trie.startsWith("app") << endl;
  trie.insert("app");
  cout << trie.search("app") << endl;
  return 0;
}