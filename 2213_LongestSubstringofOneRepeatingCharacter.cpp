#include <local_leetcode.hpp>


class SegmentTree {
  private:
    struct Node {
      int len;

      char lChar;
      char rChar;

      int lLen;
      int rLen;
    };

    int n;
    vector<Node> st; // segment tree

    /**
     * @brief 
     * 
     * @param s string
     * @param ss segment start
     * @param se segment end
     * @param si segment index on segment tree
     * @return Node& segment tree node
     */
    Node& constructImpl(const string& s, int ss, int se, int si) {
      Node& root = st[si];
      if (ss == se) {
        root.len = root.lLen = root.rLen = 1;
        root.lChar = root.rChar = s[ss];
      }
      else {
        int sm = ss + (se - ss) / 2;

        Node& left = constructImpl(s, ss, sm, si*2 + 1);
        Node& right = constructImpl(s, sm+1, se, si*2 + 2);

        root.lChar = left.lChar;
        root.rChar = right.rChar;

        root.lLen = left.lLen;
        root.rLen = right.rLen;

        root.len = max(left.len, right.len);

        if (left.rChar == right.lChar) {
          // need to further update len
          root.len = max(root.len, left.rLen + right.lLen);

          if (left.lLen == sm - ss + 1)
            root.lLen = left.lLen + right.lLen;

          if (right.rLen == se - sm)
            root.rLen = right.rLen + left.rLen;
        }
      }

      return root;
    }

    /**
     * @brief update segment tree modifying char c at index q
     * 
     * @param c char to be overwritten at q
     * @param q update index on string
     * @param ss segment start
     * @param se segment end
     * @param si segment index on segment tree
     * @return Node& segment tree node
     */
    Node& updateImpl(char c, int q, int ss, int se, int si) {
      Node& root = st[si];

      if (q < ss || q > se) {
        // pass
      }
      else if (ss == se)
        root.lChar = root.rChar = c;
      else {
        int sm = ss + (se - ss) / 2;

        Node& left = updateImpl(c, q, ss, sm, si*2 + 1);
        Node& right = updateImpl(c, q, sm + 1, se, si*2 + 2);

        if (q <= sm) {
          root.lChar = left.lChar;
          root.lLen = left.lLen;
        }
        else {
          root.rLen = right.rLen;
          root.rChar = right.rChar;
        }

        root.len = max(left.len, right.len);

        if (left.rChar == right.lChar) {
          // need to further update len
          root.len = max(root.len, left.rLen + right.lLen);

          // left only has one type of char
          if (left.lLen == sm - ss + 1)
            root.lLen = left.lLen + right.lLen;

          // right only has one type of char
          if (right.rLen == se - sm)
            root.rLen = right.rLen + left.rLen;
        }
      }

      return root;
    }

  public:
    SegmentTree(const string& s): n(s.size()) {
      int i = 1;
      while ((1 << i) < n)
        ++i;

      ++i;

      st.resize((1 << i) - 1);

      constructImpl(s, 0, n - 1, 0);
    }

    void update(char c, int i) {
      updateImpl(c, i, 0, n - 1, 0);
    }

    int query() { return st[0].len; }
};


class Solution {
  public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
      int n = queryCharacters.size();

      SegmentTree st(s);

      vector<int> res(n);
      
      for (int i = 0; i < n; ++i) {
        st.update(queryCharacters[i], queryIndices[i]);
        res[i] = st.query();
      }

      return res;
    }
};


int main() {
  EXECS(Solution::longestRepeating);
  return 0;
}