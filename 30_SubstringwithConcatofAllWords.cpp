#include <local_leetcode.hpp>

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

    vector<int> findSubstringNew(string s, vector<string>& words) {
      int n = s.size(); // length of s
      int m = words[0].size(); // length of words
      int p = words.size(); // num. of words

      int uid = 0;

      vector<int> count_orig; // uid, count
      unordered_map<string_view, int> str2idx; // word, uid
      for (string &w : words) {
        string_view v(w);
        if (str2idx.find(v) == str2idx.end()) {
          str2idx[v] = uid++;
          count_orig.push_back(1);
        }
        else
          ++count_orig[str2idx[v]];
      }

      vector<int> res;
      
      int count[uid];
      for (int i = 0; i < m; ++i) {
        int len = 0; // num. of words
        int used_up = 0; // num. of distinct words exactly used up (count == 0)
        memcpy(count, count_orig.data(), sizeof(count));

        unordered_map<string_view, int>::iterator iter;
        for (int j = i; j + m <= n; j += m) {
          string_view v(s.data() + j, m);

          iter = str2idx.find(v);
          // word not found in words.
          if (iter == str2idx.end()) {
            // not enough chars for valid substring
            if (j + m + m * p > n)
              break;
            // reset conditions
            else {
              len = 0;
              used_up = 0;
              memcpy(count, count_orig.data(), sizeof(count));
            }
          }
          else {

            int back_idx = iter->second;
            if (--count[back_idx] == 0)
              ++used_up;
            
            if (len < p)
              ++len;
            else {
              int front_idx = str2idx[string_view(s.data() + j - m * p, m)];

              if (count[front_idx]++ == 0)
                --used_up;
            }

            if (count[back_idx] == 0 && len == p && used_up == uid)
              res.push_back(j - m * p + m);
          }
        }
      }

      return res;
    }
};


int main() {
  /*
  Solution sol;
  vector<string> words = {"bar","foo","the"};
  string s = "barfoofoobarthefoobarman";
  // vector<string> words = {"foo","bar", "the"};
  // string s = "barfoofoobarthefoobarman";

  vector<int> res = sol.findSubstring(s, words);
  copy(res.begin(), res.end(), ostream_iterator<int>(cout, ", "));
  */
  EXECS(Solution::findSubstring);
  EXECS(Solution::findSubstringNew);
  return 0;
}