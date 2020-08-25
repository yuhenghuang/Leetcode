#include <vector>
#include <string>
#include <iostream>

using namespace std;

struct TrieNode {
  bool leaf;
  TrieNode *dict[26] = {0};
  TrieNode(): leaf(false) { }

  TrieNode* findAdd(char c) {
    if (dict[c-'a']==nullptr)
      dict[c-'a'] = new TrieNode();
    return dict[c-'a'];
  }

  TrieNode* find(char c) {
    return dict[c-'a'];
  }
};

class StreamChecker {
  private:
    TrieNode *root;
    vector<char> ss;
  public:
    typedef vector<char>::reverse_iterator iter_type;
    StreamChecker(vector<string>& words) {
      ss.reserve(40000);

      root = new TrieNode();

      TrieNode *node;
      for (string &w : words) {
        auto iter = w.rbegin();
        node = root;
        while (iter!=w.rend()) {
          node = node->findAdd(*iter);
          ++iter;
        }
        node->leaf = true;
      }
    }

    bool search(TrieNode *node, iter_type iter) {
      if (!node || (!node->leaf && iter==ss.rend()))
        return false;
      return node->leaf ? true : search(node->find(*iter), iter+1);
    }
    
    bool query(char letter) {
      ss.push_back(letter);
      return search(root, ss.rbegin());
    }
};

int main() {
  vector<string> words = {"cd", "f", "kl"};
  StreamChecker sc(words);

  for (int i=0; i<12; ++i)
    cout << sc.query('a'+i) << endl;
  return 0;
}