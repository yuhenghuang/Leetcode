#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <iterator>
#include <iostream>

using namespace std;

class Solution {
  private:
    void restore(queue<int> &q, vector<int> &count) {
      while (!q.empty()) {
        ++count[q.front()];
        q.pop();
      }
    }
  public:
    vector<int> findSubstring(string s, vector<string>& words) {
      int n = s.size(), p = words.size(), k = words[0].size();

      int uid = -1;
      vector<int> count;
      unordered_map<string, int> m;
      for (string &w : words) {
        if (m.find(w)==m.end()) {
          m[w] = ++uid;
          count.push_back(0);
        }
        ++count[m[w]];
      }

      vector<int> res;
      queue<int> q;
      int idx;
      unordered_map<string, int>::iterator iter;
      for (int i=0; i<k; ++i) {
        restore(q, count);
        for (int j=i; j+k<=n; j+=k) {
          iter = m.find(s.substr(j, k));
          if (iter==m.end()) 
            restore(q, count);
          else {
            idx = iter->second;
            if (count[idx]>0) 
              --count[idx];
            else {
              while (q.front()!=idx) {
                ++count[q.front()];
                q.pop();
              }
              q.pop();
            }

            q.push(idx);
            if (q.size()==p) {
              res.push_back(j-(p-1)*k);

              ++count[q.front()];
              q.pop();
            }
          }
        }
      }
      return res;
    }
};


int main() {
  Solution sol;
  vector<string> words = {"bar","foo","the"};
  string s = "barfoofoobarthefoobarman";
  // vector<string> words = {"foo","bar", "the"};
  // string s = "barfoofoobarthefoobarman";

  vector<int> res = sol.findSubstring(s, words);
  copy(res.begin(), res.end(), ostream_iterator<int>(cout, ", "));
  return 0;
}