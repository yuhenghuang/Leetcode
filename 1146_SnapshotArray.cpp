#include "utils3.hpp"

class SnapshotArray {
  private:
    vector<unordered_map<int, int>> archive;
    unordered_map<int, int> m;

  public:
    SnapshotArray(int length) { }
    
    void set(int index, int val) {
      m[index] = val;
    }
    
    int snap() {
      archive.push_back(m);
      return archive.size() - 1;
    }
    
    int get(int index, int snap_id) {
      return archive[snap_id][index];
    }
};


class SnapshotArrayPreallocate {
  private:
    int snap_total;
    vector<map<int, int, greater<int>>> arr;

  public:
    SnapshotArrayPreallocate(int length): arr(length), snap_total(0) { }
    
    void set(int index, int val) {
      arr[index][snap_total] = val;
    }
    
    int snap() {
      return snap_total++;
    }
    
    int get(int index, int snap_id) {
      if (snap_id >= snap_total)
        return 0;

      map<int, int, greater<int>>& m = arr[index];
      auto iter = m.lower_bound(snap_id);
      return iter == m.end() ? 0 : iter->second;
    }
};


int main() {
  UFUNCX(
    CTOR(int),
    &SnapshotArray::set,
    &SnapshotArray::snap,
    &SnapshotArray::get
  );
  UFUNCX(
    CTOR(int),
    &SnapshotArrayPreallocate::set,
    &SnapshotArrayPreallocate::snap,
    &SnapshotArrayPreallocate::get
  );
  return 0;
}