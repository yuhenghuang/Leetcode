#include <vector>
#include <forward_list>
#include <algorithm>
using namespace std;

class MyHashSet {
  private:
    size_t num_bucket, size;
    vector<forward_list<int>> container;
  public:
    /** Initialize your data structure here. */
    MyHashSet() {
      num_bucket = 4;
      size = 0;
      container.resize(num_bucket);
    }

    void expand() {
      num_bucket *= 2;
      vector<forward_list<int>> temp(num_bucket);
      for (auto& bucket : container) 
        for (auto key : bucket) 
          temp[key%num_bucket].push_front(key);
      container = temp;      
    }
    
    void add(int key) {
      forward_list<int> &bucket = container[key%num_bucket];
      auto iter = find(bucket.begin(), bucket.end(), key);
      if (iter==bucket.end()) {
        if (size==num_bucket) {
          expand();
        }
        ++size;
        container[key%num_bucket].push_front(key);
      }
    }
    
    void remove(int key) {
      forward_list<int> &bucket = container[key%num_bucket];
      auto q = bucket.before_begin(), p = bucket.begin();
      while (p!=bucket.end() && *p!=key) {
        ++p;
        ++q;
      }
      if (p!=bucket.end()) {
        bucket.erase_after(q);
        --size;
      }
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
      forward_list<int> &bucket = container[key%num_bucket];
      return find(bucket.begin(), bucket.end(), key) != bucket.end();
    }
};