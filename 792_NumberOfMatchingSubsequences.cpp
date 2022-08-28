#include <local_leetcode.hpp>

class Solution {
  public:
    int numMatchingSubseq(string s, vector<string>& words) {

      // store the indices of each character (a-z) in ascending order
      vector<vector<int>> indices(26);
      for (int i = 0; i < s.size(); ++i)
        indices[s[i] - 'a'].push_back(i);

      vector<int>::iterator iter;

      int res = 0;
      for (string& w : words) {
        int i = -1; // index (in s) of last character (in w)
        bool flag = true; // flag indicating w as a subsequence of s
        for (char c : w) {
          vector<int>& vec = indices[c - 'a'];

          // search for the index (in s) of char c that's greater than i
          iter = upper_bound(vec.begin(), vec.end(), i);

          // if not found, then w is not a subsequence of s
          if (iter == vec.end()) {
            flag = false;
            break;
          }
          // otherwise update index i
          else
            i = *iter;
        }

        if (flag)
          ++res;
      }

      return res;
    }

    int numMatchingSubseqIterator(string s, vector<string>& words) {

      // store the indices of each character (a-z) in ascending order
      vector<vector<int>> indices(26);
      for (int i = 0; i < s.size(); ++i)
        indices[s[i] - 'a'].push_back(i);

      typedef typename vector<int>::const_iterator iter_type;

      iter_type it;
      vector<pair<iter_type, iter_type>> iters(26);

      for (int i = 0; i < 26; ++i)
        iters[i] = {indices[i].cbegin(), indices[i].cend()};

      int res = 0;
      for (string& w : words) {

        // reset iterators
        for (int i = 0; i < 26; ++i)
          iters[i].first = indices[i].cbegin();

        int i = -1; // index (in s) of last character (in w)
        bool flag = true; // flag indicating w as a subsequence of s
        for (char c : w) {
          auto& p = iters[c - 'a'];

          // search for the index (in s) of char c that's greater than i
          it = upper_bound(p.first, p.second, i);

          // if not found, then w is not a subsequence of s
          if (it == p.second) {
            flag = false;
            break;
          }
          // otherwise update index i
          else {
            i = *it;
            p.first = it + 1;
          }
        }

        if (flag)
          ++res;
      }

      return res;
    }
};


int main() {
  EXECS(Solution::numMatchingSubseq);
  EXECS(Solution::numMatchingSubseqIterator);
  return 0;
}