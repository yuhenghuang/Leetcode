#include <local_leetcode.hpp>

// skip 
// bucket sort, counting sort
// merge sort

class Solution {
  public:
    vector<int> sortArray(vector<int>& nums) {
      
      // stack overflow on corner case
      function<void (int, int)> qsort = [&nums, &qsort] (int i, int j) {
        if (i > j)
          return;

        // solved case where the array is already sorted
        // can't solve the case where the array has only one value
        swap(nums[j], nums[i + (rand() % (j - i + 1))]);

        int pivot = nums[j];
        
        int k = i;
        for (int l = i ; l < j; ++l)
          if (nums[l] < pivot) {
            if (l > k)
              swap(nums[l], nums[k]);

            ++k;
          }
        
        swap(nums[j], nums[k]);

        qsort(i, k - 1);
        qsort(k + 1, j);
      };

      vector<int> temp(nums.size());
      function<void (int, int)> merge_sort = [&nums, &temp, &merge_sort](int low, int high) {
        if (low >= high)
          return;

        int mid = low + (high - low) / 2;

        merge_sort(low, mid);
        merge_sort(mid+1, high);

        int i = low; // index of left half
        int j = mid + 1; // index of right half
        int k = 0; // index of temp array
        while (i <= mid && j <= high) {
          if (nums[i] < nums[j])
            temp[k++] = nums[i++];
          else
            temp[k++] = nums[j++];
        }

        for (; i <= mid; ++i)
          temp[k++] = nums[i];
        for (; j <= high; ++j)
          temp[k++] = nums[j];

        copy(
          temp.begin(), temp.begin() + k,
          nums.begin() + low
        );
      };

      // qsort(0, (int) nums.size() -1);
      merge_sort(0, (int) nums.size() - 1);

      return nums;
    }

    vector<int> sortArrayBucket(vector<int>& nums) {
      constexpr int offset = 5e4;
      constexpr int size = 1e5 + 1;

      int buckets[size] = {0};

      for (const int& num : nums)
        ++buckets[num + offset];

      auto iter = nums.begin();
      for (int i = 0; i < size; ++i)
        while (buckets[i]--)
          *iter++ = i - offset;

      return nums;
    }
};


int main() {
  EXECS(Solution::sortArray);
  EXECS(Solution::sortArrayBucket);
  return 0;
}