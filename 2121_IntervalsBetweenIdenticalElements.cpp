#include <local_leetcode.hpp>

class Solution {
  private:
    template <typename Iterator>
    void iterate(Iterator curr, Iterator end, vector<long long>& res) {
      long long dist = 0;
      int count = 1;
      Iterator prev = curr++;
      for (; curr != end; ++prev, ++curr) {
        dist += abs(*curr - *prev) * count;
        res[*curr] += dist;
        ++count;
      }

    }

  public:
    vector<long long> getDistances(vector<int>& arr) {
      int n = arr.size();

      unordered_map<int, vector<int>> m;
      for (int i = 0; i < n; ++i)
        m[arr[i]].push_back(i);

      vector<long long> res(n);
      for (auto& p : m) {
        vector<int>& vec = p.second;
        iterate(vec.begin(), vec.end(), res);
        iterate(vec.rbegin(), vec.rend(), res);
      }

      return res;
    }
};


int main() {
  EXECS(Solution::getDistances);
  return 0;
}