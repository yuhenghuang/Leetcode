import java.util.List;
import java.util.ArrayList;

public class BinaryTreePath {
  List<String> res;
  public List<String> binaryTreePaths(TreeNode root) {
    res = new ArrayList<>();
    dfs(root, "");
    return res;
  }

  public void dfs(TreeNode root, String str) {
    if (root==null) return;
    String s = str+String.valueOf(root.val);
    if (root.left==null && root.right==null) 
      res.add(s);
    else {
      dfs(root.left, s+"->");
      dfs(root.right, s+"->");
    }
  }
}