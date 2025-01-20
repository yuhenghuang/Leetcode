#include <local_leetcode.hpp>

class RandomizedSet {
  private:
    // value to index
    unordered_map<int, int> dict;
    // index to value
    vector<int> vec;
    int size;
  public:
    /** Initialize your data structure here. */
    RandomizedSet() {
      size = 0;
      srand(clock());
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
      auto iter = dict.find(val);
      if (iter==dict.end()) {
        dict.emplace(val, size++);
        vec.push_back(val);
        return true;
      }
      else
        return false;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
      auto iter = dict.find(val);
      if (iter!=dict.end()) {
        --size;
        dict.find(vec[size])->second = iter->second;
        vec[iter->second] = vec[size];
        vec.pop_back();
        dict.erase(iter);
        return true;
      }
      else
        return false;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
      return vec[rand() % size];
    }
};

int main() {
  EXECX(
    CTOR(),
    &RandomizedSet::insert,
    &RandomizedSet::remove,
    &RandomizedSet::getRandom
  );
  return 0;
}