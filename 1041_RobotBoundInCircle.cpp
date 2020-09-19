#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>

using namespace std;

// wrong answer

class Triple {
  public:
    int x, y, d;
    Triple() {};
    Triple(int &x, int &y, int &d): x(x), y(y), d(d) {}

    bool operator==(const Triple& b) const {
      return (x==b.x) && (y==b.y) && (d==b.d); 
    }
};

template <typename T>
inline void hash_combine(size_t& seed, const T& val) {
  seed ^= hash<T>()(val) + 0x9e3779b9 + (seed<<6) + (seed>>2);
}

inline void hash_val(size_t &seed) { }

template <typename T, typename... Types>
inline void hash_val(size_t& seed, const T& val, const Types& ...args) {
  hash_combine(seed, val);
  hash_val(seed, args...);
}

template <typename... Types>
inline size_t hash_val(const Types& ...args) {
  size_t seed=0;
  hash_val(seed, args...);
  return seed;
}

class TripleHash {
  public:
    size_t operator()(const Triple& t) const {
      return hash_val(t.x, t.y, t.d);
    }
};

class Solution {
  private:
    int steer[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
  public:
    bool isRobotBounded(string instructions) {
      unordered_set<Triple, TripleHash> s;
      int x=0, y=0, dir = 0;
      for (char& c : instructions) {
        switch (c) {
          case 'L':
            dir = (dir-1)%4;
            break;
          case 'R':
            dir = (dir+1)%4;
            break;
          case 'G':
            x += steer[dir][0];
            y += steer[dir][1];
            break;
          default: break;
        }
        Triple t(x, y, dir);
        if (s.find(t)!=s.end())
          return true;
        s.insert(t);
      }
      return false;
    }
};

int main() {
  string instructions;
  getline(cin, instructions);

  Solution sol;
  cout << sol.isRobotBounded(instructions) << endl;

  return 0;
}