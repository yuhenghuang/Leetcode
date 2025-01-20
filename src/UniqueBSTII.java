import java.util.List;
import java.util.ArrayList;

public class UniqueBSTII {
  public static void main(String[] args) {
    UniqueBSTII obj = new UniqueBSTII();
    System.out.println(obj.generateTrees(5));
  }
  ArrayList<TreeNode>[][] memo;
  public List<TreeNode> generateTrees(int n) {
    //memo = new ArrayList[n+1][n+1];
    return dp(1, n);
  }

  public List<TreeNode> dp(int m, int n) {
    ArrayList<TreeNode> res = new ArrayList<>();
    if (m>n) return res;
    if (memo[m][n]!=null) return memo[m][n];
    for (int i=m; i<=n; i++) {
      TreeNode root = new TreeNode(i);
      List<TreeNode> left = dp(m, i-1);
      List<TreeNode> right = dp(i+1, n);
      if (!left.isEmpty()) {
        for (TreeNode l : left) {
          root.left=l;
          if (!right.isEmpty()) {
            for (TreeNode r : right) {
              root.right=r;
              res.add(root);
            }
          }
          else res.add(root);
        }
      }
      else {
        if (!right.isEmpty()) {
          for (TreeNode r : right) {
            root.right=r;
            res.add(root);
          }
        }
        else res.add(root);
      }
    }
    memo[m][n]=res;
    return res;
  }
}