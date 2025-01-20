#include <unordered_set>
#include "utils3.hpp"

size_t hash_func(string& s) {
  size_t seed = 0;
  for (char c : s) {
    seed ^= c + 0x9e3779b9 + (seed<<6) + (seed>>2);
  }
  return seed;
}

class Solution {
  public:
    string longestDupSubstring(string s) {
      int n = s.length();
      unordered_set<string_view> hash_set;

      int st=0, le=0;
      int l = 1, r = n-1;
      while (l<=r) {
        int len = l + (r-l)/2;
        bool flag = false;
        for (int i=0; i<n-len+1; ++i) {
          auto p = hash_set.emplace(s.data()+i, len);
          if (!p.second) {
            flag = true;
            st = i;
            le = len;
            break;
          }
        }

        hash_set.clear();
        if (flag)
          l = len+1;
        else
          r = len-1;
      }

      return s.substr(st, le);
    }

    string longestDupSubstringTLE(string S) {
      // TLE
      // plz simply use unordered_set ...
      unordered_map<size_t, vector<string>> hash_map;
      int n = S.size(), l = 2, r = n, m;
      string res = "";
      while (l<r) {
        hash_map.clear();
        m = l + (r-l)/2;

        bool flag=false;
        for (int i=0; i+m<=n; ++i) {
          string ss = S.substr(i, m);
          size_t hash_val = hash_func(ss);
          auto iter = hash_map.find(hash_val);
          if (iter!=hash_map.end()) {
            auto& vec = iter->second;
            if (find(vec.begin(), vec.end(), ss)!=vec.end()) {
              if (m>res.size()) res = ss;
              flag = true;
              break;
            }
            else
              vec.push_back(ss);
          }
          else {
            hash_map.insert(make_pair(hash_val, vector<string>{ss}));
          }
        }

        if (flag)
          l = m+1;
        else
          r = m;
      }
      return res;
    }

    string longestDupSubstringWrong(string s) {
      // wrong answer
      int n = s.size();
      int cnt[26] = {0};
      for (char c : s)
        ++cnt[c-'a'];

      int d_max=0;
      for (int i=0; i<26; ++i)
        if (cnt[i]>1)
          ++d_max;

      int st=0, len=0;
      for (int d=1; d<=d_max; ++d) {
        int l = 0, r = 0;
        int pos = 0, qua = 0;
        memset(cnt, 0, 26*sizeof(int));

        while (r<n) {
          if (pos>d || qua>d) 
          {
            int idx = s[l++] - 'a';
            --cnt[idx];

            if (cnt[idx]==0)
              --pos;
            else if (cnt[idx]==1)
              --qua;
          }
          else {
            int idx = s[r++] - 'a';
            ++cnt[idx];

            if (cnt[idx]==1)
              ++pos;
            else if (cnt[idx]==2)
              ++qua;

            if (pos==d && qua==d && (r-l)>len) {
              st = l;
              len = r-l;
            }
          }
        }
      }

      return s.substr(st, len);
    }
};

int main() {
  UFUNCS(Solution::longestDupSubstring);
  return 0;
}