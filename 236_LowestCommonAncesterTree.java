import java.util.HashMap;
import java.util.Map;
import java.util.Stack;

class LowestCommonAncesterTree {
  TreeNode ans;
  int p, q;
  public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
    ans = null;
    this.p = p.val;
    this.q = q.val;
    dfs(root);
    return ans;
  }

  int dfs(TreeNode node) {
    int res=0;
    if (node==null) return res;
    if (node.val==p || node.val==q)
      res++;
    res +=dfs(node.left);
    res +=dfs(node.right);
    if (res>1 && ans==null)
      ans = node;
    return res;
  }


  public TreeNode lowestCommonAncestorIter(TreeNode root, TreeNode p, TreeNode q) {
    Stack<TreeNode> stack = new Stack<>();
    Map<Integer, Boolean> seen = new HashMap<>();
    while (stack.size()>1 || root!=null) {
      while (root!=null) {
        if (root==p || root==q) 
          seen.put(root.val, true);
        else 
          seen.put(root.val, false);
        stack.push(root);
        root = root.left;
      }

      while (stack.size()>1 && stack.peek().right==null) {
        boolean prev = seen.get(stack.pop().val);
        boolean next = seen.get(stack.peek().val);
        if (prev && next) return stack.pop();
        seen.put(stack.peek().val, prev || next);
      }

      if (!stack.isEmpty()) {
        root = stack.peek().right;
        stack.peek().right = null;
      }
    }
    return root;
  }
}