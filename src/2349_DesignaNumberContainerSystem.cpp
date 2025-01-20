#include <local_leetcode.hpp>

class NumberContainers {
  private:
    // index -> number
    unordered_map<int, int> arr;

    // number -> indicies
    unordered_map<int, set<int>> indicies;

  public:
    NumberContainers() { }
    
    void change(int index, int number) {
      auto iter = arr.find(index);

      if (iter == arr.end()) { // empty index
        arr[index] = number;
        indicies[number].insert(index);
      }
      else if (iter->second != number) { // 
        indicies[iter->second].erase(index);

        iter->second = number;
        indicies[number].insert(index);
      }
    }
    
    int find(int number) {
      auto iter = indicies.find(number);

      if (iter == indicies.end())
        return -1;

      auto& s = iter->second;
      return s.begin() == s.end() ? -1 : *s.begin();
    }
};


int main() {
  EXECX(
    CTOR(),
    &NumberContainers::change,
    &NumberContainers::find
  );
  return 0;
}