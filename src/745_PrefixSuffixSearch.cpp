#include <local_leetcode.hpp>

struct TrieNode {
  unordered_map<char, TrieNode*> dict;
  int idx = -1;

  void insert(const string& p, const string& s, int idx, int i = 0) {
    char c;

    if (i < s.size())
      c = s[i];
    else if (i == s.size())
      c ='#';
    else {
      this->idx = idx;
      
      if (p.size() + s.size() + 1 == i)
        return;

      c = p[i - s.size() - 1];
    }


    if (dict.count(c) == 0)
      dict[c] = new TrieNode();

    dict[c]->insert(p, s, idx, i + 1);
  }


  int query(const string& s, int i = 0) {
    if (s.size() == i)
      return idx;

    char c = s[i];

    if (dict.count(c) == 0)
      return -1;
    else
      return dict[c]->query(s, i + 1);
  }
};


class WordFilterOld {
  private:
    TrieNode* root;

  public:
    WordFilterOld(vector<string>& words) {
      root = new TrieNode();

      for (int i = 0; i < words.size(); ++i)
        for (int j = 0; j < words[i].size(); ++j) 
          root->insert(words[i], words[i].substr(j), i);
    }
    
    int f(string prefix, string suffix) {
      return root->query(suffix + '#' + prefix);
    }
};

class WordFilter {
  private:
    struct Node {
      int index; // index of word in words
      Node* children[26];

      Node(): index(-1), children{0} { };
    };

    Node* root;

  public:
    WordFilter(vector<string>& words) {
      for (int i = 0; i < words.size(); ++i) {
        // prefix + '#' + reversed suffix

        for (int j = 1; j < words.size(); ++j) {

        }
      }
    }
    
    int f(string prefix, string suffix) {
        
    }

    ~WordFilter() { ll::destroy(root); };
};


int main() {
  EXECX(
    CTOR(vector<string>&),
    &WordFilter::f
  );

  return 0;
}