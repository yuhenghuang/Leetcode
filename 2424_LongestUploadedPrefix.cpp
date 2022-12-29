#include <local_leetcode.hpp>

class LUPrefix {
  private:
    vector<bool> videos;
    int i;

  public:
    LUPrefix(int n): videos(n), i(0) { }
    
    void upload(int video) {
      videos[video - 1] = true;
    }
    
    int longest() {
      for (;i < (int) videos.size() && videos[i]; ++i);

      return i;
    }
};


// binary index tree version
class LUPrefixBIT {
  private:
    vector<int> bit;

    int l;

    // sum over [0, i)
    int query(int i) {
      int res = 0;

      for (; i > 0; i -= i & (-i))
        res += bit[i];

      return res;
    }


  public:
    LUPrefixBIT(int n): bit(n + 1), l(0) { }
    
    void upload(int video) {
      for (int i = video; i < (int) bit.size(); i += i & (-i))
        ++bit[i];
    }
    
    int longest() {
      int r = (int) bit.size() - 1;

      while (l <= r) {
        int m = l + (r - l) / 2;

        if (query(m) < m)
          r = m - 1;
        else
          l = m + 1;
      }

      return l = r;
    }
};


int main() {
  EXECX(
    CTOR(int),
    &LUPrefix::upload,
    &LUPrefix::longest
  );

  EXECX(
    CTOR(int),
    &LUPrefixBIT::upload,
    &LUPrefixBIT::longest
  );
  return 0;
}