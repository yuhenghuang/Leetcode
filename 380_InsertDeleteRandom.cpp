#include <unordered_map>
#include <vector>
#include <ctime>
#include <iostream>
using namespace std;


class RandomizedSet {
  private:
    unordered_map<int, int> dict;
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
        dict.insert(pair<int, int>(val, size++));
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
  RandomizedSet s;
  s.insert(0);
  s.insert(1);
  s.remove(0);
  s.insert(2);
  s.remove(1);
  cout << s.getRandom() << endl;
  return 0;
}