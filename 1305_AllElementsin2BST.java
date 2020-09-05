import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

class AllElementsin2BST {
  public List<Integer> getAllElements(TreeNode root1, TreeNode root2) {
    List<Integer> res = new ArrayList<>();
    Stack<TreeNode> stack1 = new Stack<>();
    Stack<TreeNode> stack2 = new Stack<>();


    while ((!stack1.empty() || root1!=null) || (!stack2.empty() || root2!=null)) {
      while (root1!=null) {
        stack1.push(root1);
        root1 = root1.left;
      }

      while (root2!=null) {
        stack2.push(root2);
        root2 = root2.left;
      }

      if (stack1.empty() || (!stack2.empty() && stack1.peek().val > stack2.peek().val)) {
        root2 = stack2.pop();
        res.add(root2.val);
        root2 = root2.right;
      }
      else {
        root1 = stack1.pop();
        res.add(root1.val);
        root1 = root1.right;
      }
    }

    return res;
  }
}
