#include <set>
#include "utils3.hpp"

class TimeMap {
  private:
    // key, set of time
    unordered_map<string, ::set<int, greater<int>>> recent;

    // time, value
    map<int, string> m;

  public:
    /** Initialize your data structure here. */
    TimeMap() { }
    
    void set(string key, string value, int timestamp) {
      recent[key].insert(timestamp);
      m[timestamp] = value;
    }
    
    string get(string key, int timestamp) {
      auto times = recent.find(key);
      if (times != recent.end()) {
        auto iter = times->second.lower_bound(timestamp);
        if (iter != times->second.end())
          return m[*iter];
      }

      return "";
    }
};


int main() {
  UFUNCX(
    CTOR(),
    &TimeMap::set,
    &TimeMap::get
  );
  return 0;
}