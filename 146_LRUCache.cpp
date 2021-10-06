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


class LRUCacheList {
  private:
    struct Node {
      Node* prev;
      Node* next;
      int key, val;

      Node(int _key, int _val): key(_key), val(_val) { }
    };

    void remove(Node* node) {
      node->prev->next = node->next;
      node->next->prev = node->prev;
    }

    void add(Node* node) {
      node->next = sentinel->next;
      sentinel->next->prev = node;

      sentinel->next = node;
      node->prev = sentinel;
    }

    int cap;
    Node* sentinel;

    unordered_map<int, Node*> dict;

  public:
    LRUCacheList(int _cap): cap(_cap) {
      sentinel = new Node(-1, -1);
      sentinel->prev = sentinel;
      sentinel->next = sentinel;
    }


    int get(int key) {
      // pair of key, value
      auto iter = dict.find(key);

      if (iter == dict.end())
        return -1;

      Node* node = iter->second;
      remove(node);
      add(node);
      
      return node->val;
    }

    void put(int key, int value) {
      Node* node;
      // not exists
      if (dict.count(key) == 0) {
        // remost least recent used node
        if (dict.size() == cap) {
          node = sentinel->prev;

          dict.erase(node->key);
          remove(node);
          // ignore delete for non-cxx users
          delete node;
        }

        node = new Node(key, value);
        dict[key] = node;
        add(node);
      }
      // found
      else {
        // update value
        node = dict[key];
        node->val = value;

        // update to least recent
        remove(node);
        add(node);
      }
    }
    
    // ~LRUCacheList() { utils3::destroy(sentinel); }
};


int main() {
  UFUNCX(
    CTOR(int),
    &LRUCache::get,
    &LRUCache::put
  );

  UFUNCX(
    CTOR(int),
    &LRUCacheList::get,
    &LRUCacheList::put
  );
  return 0;
}