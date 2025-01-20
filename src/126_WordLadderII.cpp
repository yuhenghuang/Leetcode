#include <unordered_set>
#include "utils3.hpp"

class Solution {
  private:
    typedef typename unordered_map<int, unordered_set<int>>::iterator iter_type;

    struct HashFunc {
      hash<int> fn;

      size_t operator()(const iter_type& x) const {
        return fn(x->first);
      }
    };

    int word_to_int(const string& s) {
      // ...
      int i = 0;
      for (auto iter = s.rbegin(); iter != s.rend(); ++iter) {
        i <<= 5;
        i ^= *iter - 'a' + 1;
      }

      return i;
    }

    void trim_path(vector<vector<int>>& res_int, 
                   vector<int>& temp, 
                   unordered_map<int, unordered_set<int>> paths, 
                   int target, int v) {
      // ...
      for (int w : paths[v]) {
        temp.push_back(w);

        if (w == target)
          res_int.push_back(temp);
        else
          trim_path(res_int, temp, paths, target, w);

        temp.pop_back();
      }
    }

    vector<vector<string>> decoding(vector<vector<int>>& res_int, unordered_map<int, string> int_to_word) {
      vector<vector<string>> res;
      for (vector<int>& path_int : res_int) {
        vector<string>& path_str = res.emplace_back();
        for (int i : path_int)
          path_str.push_back(int_to_word[i]);
      }

      return res;
    }

  public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
      int n = beginWord.size();

      vector<int> masks;

      int bits = (1 << (n * 5)) - 1;
      for (int i = 0; i < n; ++i)
        masks.push_back(bits ^ (31 << (i * 5)));

      unordered_map<int, string> int_to_word;
      unordered_map<int, unordered_set<int>> neighbors;

      for (string& w : wordList) {
        int i = word_to_int(w);

        for (int mask : masks)
          neighbors[mask & i].insert(i);

        int_to_word[i] = w;
      }

      int beginIndex = word_to_int(beginWord);
      int endIndex = word_to_int(endWord);

      unordered_set<int> s;
      s.insert(beginIndex);

      unordered_map<int, unordered_set<int>> paths;

      unordered_map<int, bool> seen;
      unordered_map<int, bool> seen_next;

      int_to_word[beginIndex] = beginWord;
      seen[beginIndex] = true;

      while (!s.empty()) {
        unordered_set<int> s_next;
        unordered_set<iter_type, HashFunc> visited_edges;

        bool flag = false;
        for (int v : s) {
          for (int mask : masks) {
            unordered_set<int>& ws = paths[v];

            auto p = neighbors.find(mask & v);
            if (p != neighbors.end()) {
              for (int w : p->second) 
                if (!seen[w]) {
                  seen_next[w] = true;
                  s_next.insert(w);
                  ws.insert(w);

                  if (w == endIndex)
                    flag = true;
                }
              
              visited_edges.insert(p);
            }
          }
        }

        if (flag) {
          vector<int> temp {beginIndex};
          vector<vector<int>> res_int;
          trim_path(res_int, temp, paths, endIndex, beginIndex);

          return decoding(res_int, int_to_word);
        }

        for (auto& p : visited_edges)
          neighbors.erase(p);

        swap(s, s_next);
        seen = seen_next;
      }

      return {};
    }
};


int main() {
  UFUNCS(Solution::findLadders);
  return 0;
}