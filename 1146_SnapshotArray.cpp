#include <local_leetcode.hpp>

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
      archive.push_back(std::move(m));
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
    SnapshotArrayPreallocate(int length): snap_total(0), arr(length) { }
    
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


class SnapshotArrayNew {
  private:
    typedef pair<int, int> ii_t;

    int n_snapshots;
    // index, (snap_id, value)
    vector<vector<ii_t>> arr;

  public:
    SnapshotArrayNew(int length): n_snapshots(0), arr(length) { }
    
    void set(int index, int val) {
      vector<ii_t>& history = arr[index];

      if (!history.empty() && history.back().first == n_snapshots)
        history.back().second = val;
      else
        history.emplace_back(n_snapshots, val);
    }
    
    int snap() {
      return n_snapshots++;
    }
    
    int get(int index, int snap_id) {
      if (snap_id >= n_snapshots)
        return 0;

      vector<ii_t>& history = arr[index];

      // upper_bound is deleted for this specialization...
      // use lower_bound and `<=` to achieve the same goal
      // using reverse_iterator is more readable whereas more costly
      auto iter = lower_bound(
        history.begin(), history.end(),
        snap_id,
        [] (const ii_t& p, const int& t) -> bool { return p.first <= t; }
      );

      return iter == history.begin() ? 0 : (--iter)->second;
    }
};


int main() {
  EXECX(
    CTOR(int),
    &SnapshotArray::set,
    &SnapshotArray::snap,
    &SnapshotArray::get
  );
  EXECX(
    CTOR(int),
    &SnapshotArrayPreallocate::set,
    &SnapshotArrayPreallocate::snap,
    &SnapshotArrayPreallocate::get
  );
  EXECX(
    CTOR(int),
    &SnapshotArrayNew::set,
    &SnapshotArrayNew::snap,
    &SnapshotArrayNew::get
  );
  return 0;
}