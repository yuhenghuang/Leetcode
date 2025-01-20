#include <local_leetcode.hpp>

class Allocator {
  private:
    // mID, (start index, length)
    unordered_map<int, map<int, int>> allocated;
    // start index, length
    map<int, int> memory;

    // allocate/deallocate memory at index i of length l 
    void insert(map<int, int>& m, int i, int l) {
      auto iter = m.lower_bound(i + l);

      // try merging the memory behind [i, i + l)
      // update lengh l and erase memory if possible
      if (iter != m.end() && iter->first == i + l) {
        l += iter->second;
        iter = m.erase(iter);
      }

      if (iter != m.begin())
        --iter;

      // try merging the memory in front of [i, i + l)
      if (iter != m.end() && iter->first + iter->second == i)
          iter->second += l;
      else
        m[i] = l;
    }

  public:
    Allocator(int n) {
      memory[0] = n;
    }
    
    int allocate(int size, int mID) {
      // look for target block
      auto iter = memory.begin();
      for (;iter != memory.end() && iter->second < size; ++iter);

      if (iter == memory.end())
        return -1;
      else {
        auto [i, l] = *iter;
        insert(allocated[mID], i, size);

        memory.erase(iter);
        memory[i + size] = l - size;

        return i;
      }
    }
    
    int free(int mID) {
      auto& m = allocated[mID];
      int units = 0;

      for (auto& [i, l] : m) {
        insert(memory, i, l);
        units += l;
      }

      m.clear();

      return units;
    }
};


int main() {
  EXECX(
    CTOR(int),
    &Allocator::allocate,
    &Allocator::free
  );
  return 0;
}