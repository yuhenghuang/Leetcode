#include "utils3.hpp"

class FindSumPairs {
  private:
    vector<int>& nums2;
    map<int, int> freq1;
    unordered_map<int, int> freq2;

  public:
    FindSumPairs(vector<int>& nums1, vector<int>& _nums2): nums2(_nums2) {
      for (int num : nums1) ++freq1[num];
      for (int num : _nums2) ++freq2[num];
    }
    
    void add(int index, int val) {
      --freq2[nums2[index]];
      ++freq2[nums2[index] += val];
    }
    
    int count(int tot) {
      int res = 0;

      unordered_map<int, int>::iterator iter2;
      for (auto iter1 = freq1.begin(); iter1 != freq1.end() && iter1->first < tot; ++iter1) {
        iter2 = freq2.find(tot - iter1->first);
        if (iter2 != freq2.end())
          res += iter1->second * iter2->second;
      }
      return res;
    }
};


int main() {
  UFUNCX(
    CTOR(vector<int>&, vector<int>&),
    &FindSumPairs::add,
    &FindSumPairs::count);
  return 0;
}