#include <queue>
#include <unordered_set>
using namespace std;

class FirstUnique {
  private:
    queue<int> q;
    unordered_set<int> s1, s2;
  public:
    FirstUnique(vector<int>& nums) {
      for (int n : nums)
        add(n);
    }
    
    int showFirstUnique() {
      while (s2.find(q.front())!=s2.end()) {
        q.pop();
      }
      return q.empty()?-1:q.front();
    }
    
    void add(int value) {
      auto iter = s2.find(value);
      if (iter!=s2.end()) return;

      iter = s1.find(value);
      if (iter!=s1.end()) {
        s2.insert(*iter);
        s1.erase(iter);
      }
      else {
        q.push(value);
        s1.insert(value);
      }
    }
};