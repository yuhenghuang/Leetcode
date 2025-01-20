import java.util.Stack;
import java.util.List;
import java.util.ArrayList;

public class MinimumDistBST {
  List<Integer> list;
  public int minDiffInBST(TreeNode root) {
    list = new ArrayList<>();
    //dfs(root);

    Stack<TreeNode> stack = new Stack<>();
    do {
      while (root!=null) {
        stack.push(root);
        root=root.left;
      }
      while (!stack.isEmpty() && stack.peek().right==null) 
        list.add(stack.pop().val);

      if (!stack.isEmpty() && stack.peek().right!=null) {
        root=stack.pop();
        list.add(root.val);
        root=root.right;
        stack.push(root);
        root=root.left;
      }
    } while (!stack.isEmpty());


    int res=Integer.MAX_VALUE;
    for (int i=1; i<list.size(); ++i)
      res=Math.min(res,list.get(i)-list.get(i-1));
    return res;
  }




  public void dfs(TreeNode root) {
    if (root==null) return;
    dfs(root.left);
    list.add(root.val);
    dfs(root.right);
  }
}