class NumArray {

  int[] nums;
  SegmentTree st;
  public NumArray(int[] nums) {
    this.nums = nums;
    st = new SegmentTree(nums);
  }
  
  public void update(int i, int val) {
    st.update(i, val - nums[i]);
    nums[i] = val;
  }
  
  public int sumRange(int i, int j) {
    return st.getSum(i, j);
  }

  class SegmentTree {
    int st[];
    int n;

    SegmentTree(int[] arr) {
      n = arr.length;
      int x = (int) (Math.ceil(Math.log(n) / Math.log(2)));

      int maxsize = (1 << (x+1)) - 1;
      st = new int[maxsize];

      if (n>0)
        constructST(arr, 0, n-1, 0);
    }

    int getMid(int s, int e) {
      return s+(e-s)/2;
    }

    int constructST(int arr[], int ss, int se, int si) {
      if (ss==se) {
        st[si] = arr[ss];
        return arr[ss];
      }

      int mid = getMid(ss, se);
      st[si] = constructST(arr, ss, mid, si*2+1) +
               constructST(arr, mid+1, se, si*2+2);
      return st[si];
    }

    int getSumUtil(int ss, int se, int qs, int qe, int si) {
      if (qs<=ss && qe>=se) return st[si];
      else if (se<qs || ss>qe) return 0;

      int mid = getMid(ss, se);
      return getSumUtil(ss, mid, qs, qe, si * 2 + 1) + getSumUtil(mid+1, se, qs, qe, si*2+2);
    }

    int getSum(int qs, int qe) {
      return getSumUtil(0, n-1, qs, qe, 0);
    }

    void updateUtil(int ss, int se, int i, int diff, int si) {
      if (i<ss || i>se) return;

      st[si] += diff;
      if (se!=ss) {
        int mid = getMid(ss, se);
        updateUtil(ss, mid, i, diff, si*2+1);
        updateUtil(mid+1, se, i, diff, si*2+2);
      }
    }

    void update(int i, int diff) {
      updateUtil(0, n-1, i, diff, 0);
    }
  }
}