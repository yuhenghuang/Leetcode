#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class RandomizedCollection {
  private:
    int size;
    vector<int> vec;
    unordered_map<int, unordered_set<int>*> val2idx;

  public:
    /** Initialize your data structure here. */
    RandomizedCollection(): size(0) { }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
      unordered_set<int>* ptr = val2idx[val];
      bool res = !ptr || ptr->size() == 0;

      if (!ptr) {
        ptr = new unordered_set<int>();
        val2idx[val] = ptr;
      }

      vec.push_back(val);
      ptr->insert(size++);

      return res;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
      unordered_set<int>* ptr_orig = val2idx[val];
      bool res = ptr_orig && ptr_orig->size() > 0;

      if (res) {
        --size;
        if (val==vec[size]) 
          ptr_orig->erase(size);
        else {
          unordered_set<int>::iterator iter_orig = ptr_orig->begin();
          int idx_orig = *iter_orig;

          unordered_set<int>* ptr_target = val2idx[vec[size]];

          swap(vec[idx_orig], vec[size]);

          ptr_orig->erase(iter_orig);
          ptr_target->erase(size);
          ptr_target->insert(idx_orig);
        }
        vec.pop_back();
      }

      return res;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
      return vec[rand() % size];
    }

    ~RandomizedCollection() {
      for (auto iter : val2idx)
        delete iter.second;
    }
};


int main() {
  RandomizedCollection obj;
  obj.insert(0);
  obj.remove(0);
  obj.insert(-1);
  obj.remove(0);
  obj.getRandom();

  return 0;
}