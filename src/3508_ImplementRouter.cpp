#include <local_leetcode.hpp>


class SegmentTree {
  private:
    struct Node {
      int val;
      unique_ptr<Node> left;
      unique_ptr<Node> right;

      Node(): val(0) {}

      Node* get_left() {
        if (!left)
          left = unique_ptr<Node>(make_unique<Node>());

        return left.get();
      }

      Node* get_right() {
        if (!right)
          right = unique_ptr<Node>(make_unique<Node>());

        return right.get();
      }
    };

    int start;
    int end;
    unique_ptr<Node> root;

    int get_mid(int l, int r) {
      return l + (r - l) / 2;
    }

    void update_impl(int i, int v, int s, int e, Node* root) {
      if (i < s or i > e)
        return;

      root->val += v;
      if (s < e) {
        int m = get_mid(s, e);
        update_impl(i, v, s, m, root->get_left());
        update_impl(i, v, m + 1, e, root->get_right());
      }
    }

    int query_impl(int qs, int qe, int ss, int se, Node* root) {
      if (qs <= ss and se <= qe)
        return root->val;
      else if (se < qs or ss > qe)
        return 0;

      int m = get_mid(ss, se);
      return query_impl(qs, qe, ss, m, root->get_left()) + query_impl(qs, qe, m + 1, se, root->get_right());
    }

  public:
    SegmentTree(): start(1), end(1e9), root(make_unique<Node>()) { }

    void update(int index, int val) {
      update_impl(index, val, start, end, root.get());
    }

    int query(int qs, int qe) {
      return query_impl(qs, qe, start, end, root.get());
    }
};

struct pairhash {
  template <typename T, typename U>
  std::size_t operator()(const std::pair<T, U> &x) const
  {
    return std::hash<T>()(x.first) ^ std::hash<U>()(x.second);
  }
};

class Router {
  private:
    typedef pair<int, int> i2_t;
    typedef tuple<int, int, int> i3_t;

    int limit;
    // (source, destination, timestamp)
    queue<i3_t> q;
    // (source, destination) of latest timestamp
    unordered_set<i2_t, pairhash> s;
    // (destination, segment tree(timestamps) )
    unordered_map<int, SegmentTree> m; 

  public:
    Router(int memoryLimit): limit(memoryLimit) { }
    
    bool addPacket(int source, int destination, int timestamp) {
      /*
        queue of (source, destination, timestamp)
        hash set (source, destination) of latest timestamp to detect duplicates
      */

      // check duplicate
      int currTime = q.empty() ? 0 : get<2>(q.back());

      if (timestamp > currTime) {
        s.clear();
        s.emplace(source, destination);
      }
      else {
        i2_t p =i2_t(source, destination);
        if (s.count(p))
          return false;
        else
          s.emplace(source, destination);
      }

      // remove oldest packet
      if (q.size() == limit) {
        auto [src, dest, t] = q.front();

        m[dest].update(t, -1);

        if (t == currTime)
          s.erase(i2_t(src, dest));

        q.pop();
      }

      // push packet
      q.emplace(source, destination, timestamp);
      m[destination].update(timestamp, 1);

      return true;
    }
    
    vector<int> forwardPacket() {
      /*
        pop queue if not empty
      */

      if (q.empty())
        return {};

      auto [src, dest, t] = q.front();

      m[dest].update(t, -1);

      if (t == get<2>(q.back()))
        s.erase(i2_t(src, dest));

      q.pop();
      return {src, dest, t};
    }
    
    int getCount(int destination, int startTime, int endTime) {
      return m[destination].query(startTime, endTime);
    }
};


class RouterFast {
  private:
    typedef pair<int, int> i2_t;
    typedef tuple<int, int, int> i3_t;

    int limit;
    // (source, destination, timestamp)
    queue<i3_t> q;
    // (source, destination) of latest timestamp
    unordered_set<i2_t, pairhash> s;
    // (destination, (timestamps, index))
    unordered_map<int, pair<vector<int>, int>> m;

  public:
    RouterFast(int memoryLimit): limit(memoryLimit) { }
    
    bool addPacket(int source, int destination, int timestamp) {
      // check duplicate
      int currTime = q.empty() ? 0 : get<2>(q.back());

      if (timestamp > currTime) {
        s.clear();
        s.emplace(source, destination);
      }
      else {
        i2_t p =i2_t(source, destination);
        if (s.count(p))
          return false;
        else
          s.emplace(source, destination);
      }

      // remove oldest packet
      if (q.size() == limit) {
        auto [src, dest, t] = q.front();

        ++m[dest].second;

        if (t == currTime)
          s.erase(i2_t(src, dest));

        q.pop();
      }

      // push packet
      q.emplace(source, destination, timestamp);
      m[destination].first.push_back(timestamp);

      return true;
    }
    
    vector<int> forwardPacket() {
      if (q.empty())
        return {};

      auto [src, dest, t] = q.front();

      ++m[dest].second;

      if (t == get<2>(q.back()))
        s.erase(i2_t(src, dest));

      q.pop();
      return {src, dest, t};
    }
    
    int getCount(int destination, int startTime, int endTime) {
      auto& [vec, index] = m[destination];

      auto bg = vec.begin() + index;

      auto left = lower_bound(bg, vec.end(), startTime);
      auto right = upper_bound(bg, vec.end(), endTime);

      return right - left;
    }
};


int main() {
  EXECX(
    CTOR(int),
    &Router::addPacket,
    &Router::forwardPacket,
    &Router::getCount
  );

  EXECX(
    CTOR(int),
    &RouterFast::addPacket,
    &RouterFast::forwardPacket,
    &RouterFast::getCount
  );
  return 0;
}