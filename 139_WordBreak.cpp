/*
#include "utils.hpp"
#include <unordered_map>
#include <unordered_set>

using namespace std;
*/

#include <local_leetcode.hpp>

class Solution {
  private:
    int n;

    struct Node {
      bool leaf;
      Node* children[26];

      Node(): leaf(false), children{nullptr} { }
    };


    bool dfs(int idx, string& s, unordered_map<int, unordered_set<string>>& dict, vector<int>& memo) {
      if (idx==n)
        return true;

      if (memo[idx]!=0)
        return memo[idx]>0;

      bool flag = false;
      for (auto& p: dict) {
        int len = p.first;
        if (idx+len>n) continue;

        unordered_set<string>* ptr = &p.second;
        if (ptr->find(s.substr(idx, len))!=ptr->end() && dfs(idx+len, s, dict, memo)) {
          flag = true;
          break;
        }
      }

      memo[idx] = flag ? 1 : -1;
      return flag;
    }
  public:
    bool wordBreakDFS(string s, vector<string>& wordDict) {
      n = s.length();
      if (n>100) return false;

      unordered_map<int, unordered_set<string>> dict;
      for (string& w : wordDict) {
        int len = w.length();
        dict[len].insert(w);
      }

      vector<int> memo(n, 0);
      
      return dfs(0, s, dict, memo);
    }

    bool wordBreak(string s, vector<string>& wordDict) {

      unordered_map<int, unordered_set<string>> dict;
      for (string& w : wordDict) {
        int len = w.length();
        dict[len].insert(w);
      }

      n = s.length();
      vector<bool> dp(n+1, false);
      dp[0] = true;

      for (int i=0; i<=n; ++i) {
        if (!dp[i]) continue;
        for (auto& p : dict) {
          int len = p.first;
          if (i+len>n) continue;
          unordered_set<string>* ptr = &p.second;
          if (ptr->find(s.substr(i, len)) != ptr->end()) {
            dp[i+len] = true;
          }
        }
      }
      return dp[n];
    }

    bool wordBreakTrie(string s, vector<string>& wordDict) {
      Node* root = new Node();
      for (string& w : wordDict) {
        Node* node = root;
        for (int i = w.size() - 1; i >= 0; --i) {
          int j = w[i] - 'a';
          if (node->children[j] == nullptr)
            node->children[j] = new Node();
          node = node->children[j];
        }
        node->leaf = true;
      }

      const int n = s.size();
      bool dp[n+1];
      memset(dp, false, sizeof(dp));

      dp[0] = true;

      for (int i = 0; i < n; ++i) {
        Node* node = root;
        for (int j = i; j >= 0; --j) {
          node = node->children[s[j] - 'a'];
          if (node) {
            if (node->leaf)
              dp[i+1] |= dp[j];
          }
          else
            break;
        }
      }

      ll::destroy(root);

      return dp[n];
    }
};


int main() {
  /*
  Solution sol;

  vector<string> args;
  string s;
  vector<string> wordDict;

  utils::parse_vector_1d<string> parser;

  ifstream f("Inputs/139_WordBreak.txt");
  string line;
  while (getline(f, line)) {
    args = utils::string_split(line);
    s = std::move(args[0]);
    wordDict = parser(args[1]);

    cout << sol.wordBreak(s, wordDict) << " " << sol.wordBreakDFS(s, wordDict)<< endl;
  }
  */

  EXECS(Solution::wordBreak);
  EXECS(Solution::wordBreakDFS);
  EXECS(Solution::wordBreakTrie);
  return 0;
}
