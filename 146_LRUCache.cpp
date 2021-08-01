#include <list>
#include "utils3.hpp"

class LRUCache {
  private:
    typedef pair<int, int> pii;
    typedef list<pii>::iterator iter_type;

    size_t capacity;

    // list of (key, value)
    list<pii> ls;
    unordered_map<int, iter_type> dict;

  public:
    LRUCache(int _cap): capacity(_cap) { }
    
    int get(int key) {
      auto p = dict.find(key);
      if (p == dict.end())
        return -1;

      if (p->second != ls.begin()) {
        ls.emplace_front(key, p->second->second);
        ls.erase(p->second);
        p->second = ls.begin();
      }

      return ls.front().second;
    }
    
    void put(int key, int value) {
      auto p = dict.find(key);
      if (p != dict.end()) {
        p->second->second = value;

        if (p->second != ls.begin()) {
          ls.emplace_front(key, p->second->second);
          ls.erase(p->second);
          p->second = ls.begin();
        }
      }
      else {
        ls.emplace_front(key, value);
        dict[key] = ls.begin();

        if (dict.size() > capacity) {
          dict.erase(ls.back().first);
          ls.pop_back();
        }
      }
    }
};


int main() {
  UFUNCX(
    CTOR(int),
    &LRUCache::get,
    &LRUCache::put
  );
  return 0;
}