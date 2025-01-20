#include <local_leetcode.hpp>

class TimeMap {
  private:
    typedef pair<int, string> is_t;

    // key, set of time
    unordered_map<string, ::set<int, greater<int>>> recent;

    // time, value
    vector<is_t> vec;

  public:
    /** Initialize your data structure here. */
    TimeMap() { }
    
    void set(string key, string value, int timestamp) {
      recent[key].insert(timestamp);
      vec.emplace_back(timestamp, value);
    }
    
    string get(string key, int timestamp) {
      auto times = recent.find(key);
      if (times != recent.end()) {
        auto iter = times->second.lower_bound(timestamp);
        if (iter != times->second.end()) {
          return lower_bound(vec.begin(), vec.end(), *iter, [](const is_t& p, int i) { return p.first < i; })->second;
        }
      }

      return {};
    }
};


int main() {
  EXECX(
    CTOR(),
    &TimeMap::set,
    &TimeMap::get
  );
  return 0;
}
