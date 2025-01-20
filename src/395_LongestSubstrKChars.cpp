#include "utils.hpp"

class Solution {
  private:
    static size_t count_size;

    void reset_count(int *count) {
      for (int i=0; i<26; ++i)
        count[i] = 0;
    }
  public:
    int longestSubstring(string s, int k) {
      int n = s.size();
      int count[26] = {0};

      for (int i=0; i<n; ++i)
        ++count[s[i]-'a'];

      int d_max=0;
      for (int i=0; i<26; ++i)
        if (count[i]>=k)
          ++d_max;

      int res=0;
      for (int d=1; d<=d_max; ++d) {
        int l=0, r=0;
        // detected (ocurrence>0), counted (ocurrent>=k)
        int d_curr=0, c_curr=0;
        // reset_count(count);
        memset(count, 0, count_size);
        
        while (r<n) {
          if (d_curr<=d) {
            int idx = s[r++]-'a';
            if (count[idx]==0)
              ++d_curr;
            ++count[idx];

            if (count[idx]==k)
              ++c_curr;

            if (c_curr==d && d_curr==d)
              res = max(res, r-l);
          }
          else {
            int idx = s[l++]-'a';
            if (count[idx]==k)
              --c_curr;

            --count[idx];
            if (count[idx]==0)
              --d_curr;
          }
        }
      }

      return res;
    }

    int longestSubstringAtMost(string s, int k) {
      // wrong answer
      int l=0, r=0, n=s.size();

      int res=0;
      int count[26] = {0};
      while (r<n) {

        while (r<n && count[s[r]-'a']<k) {
          ++count[s[r++]-'a'];
        }

        res = max(res, r-l);

        --count[s[l++]-'a'];
      }

      return res;
    }
};

size_t Solution::count_size = sizeof(int)*26;


int main() {
  UFUNC(Solution::longestSubstring);
  return 0;
}