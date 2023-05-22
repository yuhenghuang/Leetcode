/*
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <iterator>
using namespace std;
*/

#include <local_leetcode.hpp>

class Compare {
  private:
    unordered_map<int, int>& m;
  public:
    Compare(unordered_map<int, int>& map): m(map) {}
    bool operator()(const int& l, const int& r) const {
      return m[l] > m[r];
    }
};

class Solution {
  public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
      unordered_map<int, int> m;
      for (int& num : nums)
        ++m[num];

      vector<int> unique;
      for (auto iter=m.begin(); iter!=m.end(); ++iter)
        unique.push_back(iter->first);

      sort(unique.begin(), unique.end(), Compare(m));

      unique.resize(k);
      return unique;
    }

    vector<int> topKFrequentPQ(vector<int>& nums, int k) {
#define N 20001

      typedef pair<uint16_t, int> ii_t;

      constexpr int offset = 1e4;

      uint16_t freq[N];
      memset(freq, 0, sizeof(freq));

      for (int num : nums)
        ++freq[num + offset];

      // freq, num
      priority_queue<ii_t, vector<ii_t>, function<bool (const ii_t&, const ii_t&)>> heap(
        [] (const ii_t& p, const ii_t& q) -> bool { return p.first > q.first; }
      );


      for (int i = 0; i < N; ++i)
        if (freq[i] > 0) {
          if (heap.size() < k)
            heap.emplace(freq[i], i);
          else if (heap.top().first < freq[i]) {
            heap.pop();
            heap.emplace(freq[i], i);
          }
        }


      vector<int> res(k);
      for (int i = k - 1; i >= 0; --i) {
        res[i] = heap.top().second - offset;
        heap.pop();
      }

      return res;
    }
};

int main() {
  /*
  Solution sol;
  vector<int> nums = {4,1,-1,2,-1,2,3};
  vector<int> res = sol.topKFrequent(nums, 2);
  copy(res.begin(), res.end(), ostream_iterator<int>(cout, " "));
  */

  EXECS(Solution::topKFrequent);
  EXECS(Solution::topKFrequentPQ);
  return 0;
}
