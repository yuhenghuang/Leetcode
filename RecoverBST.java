import java.util.List;
import java.util.ArrayList;
//import java.util.Stack;

public class RecoverBST {
  int left, right;
  public void recoverTree(TreeNode root) {
    left = Integer.MIN_VALUE;
    right = Integer.MAX_VALUE;
    res = new ArrayList<>();
    dfs_l(root);
    //dfs_r(root);
    sw(root, res.get(0), res.get(1));
  }

  public void dfs_l(TreeNode node) {
    if (node==null) return;
    dfs(node.left);
    if (left>node.val) {
      if (res.isEmpty()) res.add(left);
      else res.add(node.val);
    }
    left=node.val;
    dfs(node.right);
  }

  public void dfs_r(TreeNode node) {
    if (node==null) return;
    dfs(node.right);
    if (right<node.val) {
      res.add(right); return;
    }
    right=node.val;
    dfs(node.left);
  }



  List<Integer> res;
  public void recoverTree_On(TreeNode root) {
    res = new ArrayList<>();
    dfs(root);
    int cad1=Integer.MIN_VALUE, cad2=Integer.MAX_VALUE;
    for (int i=0; i<res.size()-1; ++i)
      if (res.get(i)>res.get(i+1))
        cad1=res.get(i);

    for (int i=res.size()-1; i>0; --i)
      if (res.get(i)<res.get(i-1))
        cad2=res.get(i);

    sw(root, cad1, cad2);
  }

  private void sw(TreeNode node, int cad1, int cad2) {
    if (node==null) return;
    if (node.val==cad1) node.val=cad2;
    else if (node.val==cad2) node.val=cad1;

    sw(node.left, cad1 ,cad2);
    sw(node.right, cad1, cad2);
  }

  private void dfs(TreeNode node) {
    if (node==null) return;

    dfs(node.left);
    res.add(node.val);
    dfs(node.right);
  }
}