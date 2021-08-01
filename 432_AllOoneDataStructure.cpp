#include <unordered_set>
#include "utils3.hpp"

class AllOne {
  private:
    unordered_map<string, int> freq;
    map<int, unordered_set<string>> m;

  public:
    /** Initialize your data structure here. */
    AllOne() { }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
      int f = ++freq[key];
      if (f > 1) {
        auto iter = m.find(f-1);
        iter->second.erase(key);

        if (iter->second.empty())
          m.erase(iter);
      }

      m[f].insert(key);
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
      int f = --freq[key];

      auto iter = m.find(f+1);
      iter->second.erase(key);
      if (iter->second.empty())
        m.erase(iter);

      if (f > 0) 
        m[f].insert(key);
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
      if (m.empty())
        return "";

      return *(prev(m.end())->second.begin());
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
      if (m.empty())
        return "";

      return *(m.begin()->second.begin());
    }
};


int main() {
  UFUNCX(
    CTOR(),
    &AllOne::inc,
    &AllOne::dec,
    &AllOne::getMaxKey,
    &AllOne::getMinKey
  );
  return 0;
}