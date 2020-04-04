import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Stack;

class SmallerAfterSelf {
  public static void main(String[] args) {
    SmallerAfterSelf obj = new SmallerAfterSelf();
    System.out.println(obj.countSmaller(new int[] {5,2,6,1}));
  }

  public List<Integer> countSmaller(int[] nums) {
    int n = nums.length;
    List<Integer> res = new ArrayList<>();
    Stack<Integer> stack = new Stack<>();
    BSTNode root=null;
    for (int i = n-1; i>=0; --i) {
      stack.push(BSTSearch(root, nums[i]));
      root = BSTinsert(root, nums[i]);
    }

    while (!stack.isEmpty())
      res.add(stack.pop());
    return res;
  }

  private int BSTSearch(BSTNode root, int val) {
    if (root==null) return 0;

    if (root.val==val) return root.smallcount;
    else if (root.val > val)
      return BSTSearch(root.left, val);
    else
      return 1 + root.smallcount + BSTSearch(root.right, val);
  }

  private BSTNode BSTinsert(BSTNode root, int val) {
    if (root==null) return new BSTNode(0, val);
    
    if (root.val>val) {
      root.left = BSTinsert(root.left, val);
      root.smallcount++;
      return root;
    }
    else {
      root.right = BSTinsert(root.right, val);
      return root;
    }
  }

  class BSTNode extends TreeNode {
    int smallcount;
    BSTNode left;
    BSTNode right;
    BSTNode(int sc, int val) {
      super(val);
      smallcount = sc;
    }
  }



  public List<Integer> countSmallerBS(int[] nums) {
    int n = nums.length;
    List<Integer> res = new ArrayList<>();
    Stack<Integer> stack = new Stack<>();
    for (int i = n-1; i>=0; --i) {
      Arrays.sort(nums, i+1, n);
      int loc = Arrays.binarySearch(nums, i+1, n, nums[i]);
      if (loc<0) loc = - loc - 1;
      do {
        loc--;
      } while (loc>=i && nums[i]<=nums[loc]);

      stack.push(Math.max(loc-i, 0));
    }

    while (!stack.isEmpty())
      res.add(stack.pop());
    return res;
  }




  public List<Integer> countSmallerST(int[] nums) {
    List<Integer> res = new ArrayList<>();
    SegmentTree st = new SegmentTree(nums);
    for (int i=0; i<nums.length; i++) {
      res.add(st.RMQ(0, st.n-1, i+1, st.n-1, 0));
    }
    return res;
  }

  class SegmentTree {
    int[] st, stmin, arr;
    int n;

    SegmentTree(int[] arr) {
      n = arr.length;
      this.arr = arr;
      int power = (int) Math.ceil(Math.log(n) / Math.log(2)) + 1;
      int maxsize = (1 << (power)) - 1;
      st = new int[maxsize];
      stmin = new int[maxsize];
      
      if (n>0) {
        constructUtil(arr, 0, n-1, 0);
      }
    }

    int getMid(int s, int e) {
      return s+(e-s)/2;
    }

    int constructUtil(int[] arr, int ss, int se, int si) {
      if (ss==se) {
        st[si] = arr[ss];
        return arr[ss];
      }

      int mid = getMid(ss, se);
      st[si] = Math.max(constructUtil(arr, ss, mid, si * 2 + 1),
                        constructUtil(arr, mid+1, se, si * 2 + 2));
      return st[si];
    }

    int constructUtilMin(int[] arr, int ss, int se, int si) {
      if (ss==se) {
        stmin[si] = arr[ss];
        return arr[ss];
      }

      int mid = getMid(ss, se);
      stmin[si] = Math.min(constructUtil(arr, ss, mid, si * 2 + 1),
                        constructUtil(arr, mid+1, se, si * 2 + 2));
      return stmin[si];
    }

    int RMQ(int ss, int se, int qs, int qe, int si) {
      if (qs<=ss && qe>=se)
        if (st[si]<arr[qs-1])
          return se - ss + 1;
        else if (stmin[si]>=arr[qs-1] || ss==se) return 0;
      
      if (se<qs || ss>qe) return 0;

      int mid = getMid(ss, se);
      return RMQ(ss, mid, qs, qe, si * 2 + 1) + RMQ(mid+1, se, qs, qe, si * 2 + 2);
    }
  }
}