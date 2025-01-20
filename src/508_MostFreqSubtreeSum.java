import java.util.HashMap;
import java.util.Map;

class MostFreqSubtreeSum {
  Map<Integer, Integer> map;
  public int[] findFrequentTreeSum(TreeNode root) {
    map = new HashMap<>();
    dfs(root);

    int max=Integer.MIN_VALUE, count=0;
    for (int tmp : map.values()) {
      if (tmp>max) {
        max=tmp;
        count=1;
      }
      else if (tmp==max)
        ++count;
    }
    int[] res = new int[count];
    for (Map.Entry<Integer, Integer> tmp : map.entrySet()) 
      if (tmp.getValue()==max)
        res[--count] = tmp.getKey();
    return res;
  }

  int dfs(TreeNode root) {
    if (root==null) return 0;
    int sum = dfs(root.left) + root.val + dfs(root.right);
    map.put(sum, map.getOrDefault(sum, 0) + 1);
    return sum;
  }
}