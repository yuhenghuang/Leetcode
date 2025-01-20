#include <local_leetcode.hpp>

class Solution {
  public:
    vector<string> topKFrequent(vector<string>& words, int k) {
      unordered_map<string, int> m;
      for (auto& w : words)
        ++m[w];

      typedef pair<int, string> is_t;
      priority_queue<is_t, vector<is_t>, function<bool (const is_t&, const is_t&)>> heap(
        [](const is_t& i, const is_t& j) { return i.first > j.first || (i.first == j.first && i.second < j.second); }
      );

      for (auto& [s, i] : m) {
        if (heap.size() < k)
          heap.emplace(i, s);
        else if (heap.top().first < i || (heap.top().first == i && heap.top().second > s)) {
          heap.pop();
          heap.emplace(i, s);
        }
      }

      vector<string> res(k);
      for (int i = k - 1; i >= 0; --i) {
        res[i] = heap.top().second;
        heap.pop();
      }

      return res;
    }
};


int main() {
  EXECS(Solution::topKFrequent);
  return 0;
}