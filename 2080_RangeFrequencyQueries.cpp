#include "utils3.hpp"


class RangeFreqQuery {
  private:
    unordered_map<int, vector<int>> m;

  public:
    RangeFreqQuery(vector<int>& arr) {
      // O(n)
      for (int i = 0; i < arr.size(); ++i)
        m[arr[i]].push_back(i);
    }
    
    int query(int left, int right, int value) {
      // O(logn)
      auto iter = m.find(value);
      if (iter == m.end())
        return 0;

      vector<int>& vec = iter->second;
      return upper_bound(vec.begin(), vec.end(), right) - lower_bound(vec.begin(), vec.end(), left);
    }
};


int main() {
  UFUNCX(
    CTOR(vector<int>&),
    &RangeFreqQuery::query
  );
  return 0;
}