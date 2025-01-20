#include "utils3.hpp"

class SORTracker {
  private:
    struct Scene {
      typedef Scene self;

      int score;
      string name;

      Scene(int s, const string& n): score(s), name(n) { }
      Scene(int s, string&& n): score(s), name(std::move(n)) { }

      // copy ctor
      Scene(const self& x) = default;
      // move ctor
      Scene(self&& x): score(x.score), name(std::move(x.name)) { }

      // copy assignment
      self& operator=(const self& rhs) = default;
      // move assignment
      self& operator=(self&& rhs) {
        score = rhs.score;
        name = std::move(rhs.name);

        return *this;
      }

      // less
      bool operator<(const self& rhs) const {
        return score > rhs.score || (score == rhs.score && name < rhs.name);
      }

      // greater
      bool operator>(const self& rhs) const { return !(*this < rhs); }
    };

    priority_queue<Scene> max_heap;
    priority_queue<Scene, vector<Scene>, greater<Scene>> min_heap;

  public:
    SORTracker() {
      max_heap.emplace(0, "");
    }
    
    void add(string name, int score) {
      Scene p(score, name);

      if (p < max_heap.top()) {
        min_heap.push(max_heap.top());
        max_heap.pop();

        max_heap.push(std::move(p));
      }
      else
        min_heap.push(std::move(p));

    }
    
    string get() {
      string res = max_heap.top().name;

      max_heap.push(min_heap.top());
      min_heap.pop();

      return res;
    }
};


int main() {
  UFUNCX(
    CTOR(),
    &SORTracker::add,
    &SORTracker::get
  );
  return 0;
}