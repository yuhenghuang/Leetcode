#include <vector>
#include <iostream>

using namespace std;


class NumArray {
  private:
    int n;

    vector<int>& nums;
    vector<int> st;

    int getMid(int s, int e) {
      return s + (e - s) / 2;
    }

    int constructST(int ss, int se, int si) {
      if (ss == se)
        return st[si] = nums[ss];

      int mid = getMid(ss, se);
      return st[si] = constructST(ss, mid, si * 2 + 1) + constructST(mid + 1, se, si * 2 + 2);
    }

    void updateUtil(int qi, int ss, int se, int diff, int si) {
      if (ss <= qi && qi <= se) {
        st[si] += diff;

        if (ss != se) {
          int mid = getMid(ss, se);

          updateUtil(qi, ss, mid, diff, si * 2 + 1);
          updateUtil(qi, mid + 1, se, diff, si * 2 + 2);
        }
      }
    }

    int queryUtil(int qs, int qe, int ss, int se, int si) {
      if (ss > qe || se < qs)
        return 0;
      else if (qs <= ss && se <= qe)
        return st[si];
      
      int mid = getMid(ss, se);
      return queryUtil(qs, qe, ss, mid, si * 2 + 1) + queryUtil(qs, qe, mid + 1, se, si * 2 + 2);
    }

  public:
    NumArray(vector<int>& _nums): nums(_nums) {
      n = nums.size();

      int i = 1;
      while ((1 << i) < n)
        ++i;

      st.resize((1 << ++i) - 1);

      constructST(0, n - 1, 0);
    }
    
    void update(int i, int val) {
      updateUtil(i, 0, n - 1, val - nums[i], 0);

      nums[i] = val;
    }
    
    int sumRange(int left, int right) {
      return queryUtil(left, right, 0, n - 1, 0);
    }
};


int main() {
  vector<int> nums {9, -8};

  NumArray st(nums);

  st.update(0, 3);
  cout << st.sumRange(1, 1) << '\n';
  cout << st.sumRange(0, 1) << '\n';
  
  st.update(1, -3);
  cout << st.sumRange(0, 1) << endl;

  return 0;
}