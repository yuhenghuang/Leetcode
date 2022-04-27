#include <forward_list>
#include <local_leetcode.hpp>

class MyHashSetOld {
  private:
    size_t num_bucket, size;
    vector<forward_list<int>> container;
  public:
    /** Initialize your data structure here. */
    MyHashSetOld() {
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


class MyHashSet {
  private:
    size_t size;
    vector<forward_list<int>> buckets;

    void expand() {
      vector<forward_list<int>> temp(buckets.size() << 1);
      for (auto& b : buckets)
        for (auto& key : b) 
          temp[key % temp.size()].push_front(key);

      buckets = std::move(temp);
    }

  public:
    MyHashSet(): size(0), buckets(4) { }
    
    void add(int key) {
      forward_list<int>& b = buckets[key % buckets.size()];
      auto iter = find(b.begin(), b.end(), key);

      if (iter == b.end()) {
        if (size == buckets.size())
          expand();

        ++size;
        buckets[key % buckets.size()].push_front(key);
      }
    }
    
    void remove(int key) {
      forward_list<int>& b = buckets[key % buckets.size()];

      // to do: early stop needed?
      b.remove_if(
        [this, &key](const int& val) -> bool {
          if (val == key) {
            --size;
            return true;
          }
          return false;
        }
      );
    }
    
    bool contains(int key) {
      forward_list<int>& b = buckets[key % buckets.size()];

      return find(b.begin(), b.end(), key) != b.end();
    }
};


int main() {
  EXECX(
    CTOR(),
    &MyHashSetOld::add,
    &MyHashSetOld::contains,
    &MyHashSetOld::remove
  );

  EXECX(
    CTOR(),
    &MyHashSet::add,
    &MyHashSet::contains,
    &MyHashSet::remove
  );
  return 0;
}