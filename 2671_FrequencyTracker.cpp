#include <local_leetcode.hpp>

#define N 100001

class FrequencyTracker {
  private:
    int nums[N]; // count of numbers
    int fqs[N]; // count of numbers of frequency

  public:
    FrequencyTracker(): nums{0}, fqs{0} { }
    
    void add(int number) {
      --fqs[nums[number]++];
      ++fqs[nums[number]];
    }
    
    void deleteOne(int number) {
      if (nums[number] > 0) {
        --fqs[nums[number]--];
        ++fqs[nums[number]];
      }
    }
    
    bool hasFrequency(int frequency) {
      return fqs[frequency] > 0;
    }
};


int main() {
  EXECX(
    CTOR(),
    &FrequencyTracker::add,
    &FrequencyTracker::deleteOne,
    &FrequencyTracker::hasFrequency
  );
  return 0;
}