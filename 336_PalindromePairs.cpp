#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

struct TrieNode {
  unordered_map<char, TrieNode*> map;
  int idx;
  TrieNode(): idx(-1) {}
};

class Solution {
  private: 
    vector<vector<int>> res;
    vector<string> *words;
  public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
      TrieNode *forward = new TrieNode();
      TrieNode *backward = new TrieNode();
      for (int i=0; i<words.size(); ++i)
        addWord(forward, backward, words[i], i);
      
      this->words = &words;
      dfs(forward, backward);
      return res;
    }

    void findWords(vector<int>& indeces, TrieNode* f) {
      if (f->idx!=-1) {
        indeces.push_back(f->idx);
        return;
      }
      for (auto& p : f->map)
        findWords(indeces, p.second);
    }

    vector<int>& remain(int i, TrieNode* f) {
      vector<int>* set = new vector<int>();
      findWords(*set, f);
      for (int& i : *set) {
        
      }
    }

    void dfs(TrieNode* f, TrieNode* b) {
      if (f->idx!=-1 && b->idx!=-1) {
        if (f->idx!=b->idx)
          res.push_back({f->idx, b->idx});
        return;
      }
      else if (f->idx!=-1) {
        for (int id : remain(words[f->idx].size(), b))
          res.push_back({f->idx, id});
      }

      for (auto& p : f->map) {
        auto iter = b->map.find(p.first);
        if (iter!=b->map.end()) 
          dfs(p.second, iter->second);
      }
    }

    bool isPar(string& s, int i, int j) const {
      while (i<j) {
        if (s[i]!=s[j]) return false;
        i++; j--;
      }
      return true;
    }

    void addWord(TrieNode* f, TrieNode* b, string& w, int idx) {
      TrieNode* node = f;
      for (int i=0; i<w.size(); i++) {
        char c = w.at(i);
        if (node->map.find(c)==node->map.end())
          node->map.insert(make_pair(c, new TrieNode()));
        node = (*node->map.find(c)).second;
      }
      node->idx = idx;

      node = b;
      for (int i=w.size()-1; i>=0; ++i) {
        char c = w.at(i);
        if (node->map.find(c)==node->map.end())
          node->map.insert(make_pair(c, new TrieNode()));
        node = (*node->map.find(c)).second;
      }
      node->idx = idx;
    }
};

int main() {
  Solution sol;
  vector<string> words = {"abcd","dcba","lls","s","sssll"};
  sol.palindromePairs(words);
}