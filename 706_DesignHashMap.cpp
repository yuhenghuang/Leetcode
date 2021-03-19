#include <vector>
#include <forward_list>

using namespace std;

class MyHashMap {
  private:
    typedef forward_list<pair<int, int>> list_type;

    int size;
    int bucketSize;
    
    vector<list_type> buckets;

    void rehash() {
      bucketSize <<= 1;

      vector<list_type> tmpBuckets(bucketSize);

      for (list_type& ls : buckets) 
        for (auto& p : ls) 
          tmpBuckets[p.first % bucketSize].emplace_front(std::move(p));

      buckets = std::move(tmpBuckets);
    }

  public:
    /** Initialize your data structure here. */
    MyHashMap(): size(0), bucketSize(8), buckets(8) { }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
      if (size > (bucketSize << 1))
        rehash();

      list_type& ls = buckets[key % bucketSize];

      bool found = false;
      for (auto iter = ls.begin(); iter != ls.end(); ++iter) 
        if (iter->first == key) {
          found = true;
          iter->second = value;
          break;
        }

      if (!found) {
        ls.emplace_front(key, value);
        ++size;
      }
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
      list_type& ls = buckets[key % bucketSize];

      for (auto iter = ls.begin(); iter != ls.end(); ++iter)
        if (iter->first == key)
          return iter->second;
      
      return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
      list_type& ls = buckets[key % bucketSize];

      auto prev = ls.before_begin();
      auto iter = ls.begin();
      
      while (iter != ls.end()) {
        if (iter->first == key) {
          ls.erase_after(prev);
          --size;
          break;
        }

        ++prev;
        ++iter;
      }
    }
};