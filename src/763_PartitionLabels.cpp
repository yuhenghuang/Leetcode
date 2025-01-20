#include <local_leetcode.hpp>

class Solution {
public:
    vector<int> partitionLabels(string S) {
      int n = S.size();
      vector<vector<int>> intervals(26, vector<int>(2, n-1));
      for (int i=0; i<26; ++i)
        intervals[i][1] = 0;

      int idx;
      for (int i=0; i<n; ++i) {
        idx = S.at(i) - 'a';
        intervals[idx][0] = min(intervals[idx][0], i);
        intervals[idx][1] = max(intervals[idx][1], i);
      }

      sort(intervals.begin(), intervals.end(), [](auto &a, auto &b){ 
        return (a[0]==b[0]) ? (a[1] < b[1]) : (a[0]<b[0]);
      } );

      vector<int> res;
      int begin=0, end=0;
      for (auto &p : intervals) {
        if (p[0]>p[1]) continue;
        
        if (p[0]>end) {
          res.push_back(p[0]-begin);
          begin = p[0];
          end = p[1];
        }
        else {
          end = max(end, p[1]);
        }
      }
      res.push_back(end-begin+1);

      return res;
    }

    vector<int> partitionLabelsNew(string s) {
      vector<pair<int, int>> intervals(26, {-1, 0});

      for (int i = 0; i < s.size(); ++i) {
        int j = s[i] - 'a';
        
        if (intervals[j].first < 0)
          intervals[j].first = i;

        intervals[j].second = i;
      }

      sort(intervals.begin(), intervals.end());

      vector<int> res;
      int start = 0, end = 0;

      for (auto& [s, e] : intervals) {
        if (s > end) {
          res.push_back(s - start);
          start = s;
          end = e;
        }
        else
          end = max(end, e);
      }

      res.push_back(end - start + 1);

      return res;
    }
};

int main() {
  /*
  Solution sol;
  vector<int> res= sol.partitionLabels("ababcbacadefegdehijhklij");
  copy(res.begin(), res.end(), ostream_iterator<int>(cout, " "));
  */

  EXECS(Solution::partitionLabels);
  EXECS(Solution::partitionLabelsNew);
  return 0;
}
