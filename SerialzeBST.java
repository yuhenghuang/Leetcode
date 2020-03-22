import java.util.Stack;

public class SerialzeBST {
      // Encodes a tree to a single string.
      public String serialize(TreeNode root) {
        StringBuffer res = new StringBuffer();
        Stack<TreeNode> stack = new Stack<>();
        stack.push(root);
        while(!stack.isEmpty()) {
          TreeNode node = stack.pop();
          if (node!=null) {
            res.append(String.valueOf(node.val));
            res.append(' ');

            stack.push(node.right);
            stack.push(node.left);
          }
        }
        return res.toString().strip();
      }


      public String serialize_old(TreeNode root) {
        StringBuffer res = new StringBuffer();
        Stack<TreeNode> stack = new Stack<>();
        while (!stack.isEmpty()) {
          while (root!=null) {
            stack.push(root);
            res.append(String.valueOf(root.val));
            res.append(' ');
            root=root.left;
          }

          while (!stack.isEmpty() && stack.peek().right==null) stack.pop();
          
          if (!stack.isEmpty()) {
            root=stack.pop();
            root=root.right;
            stack.push(root);
            res.append(String.valueOf(root.val));
            res.append(' ');
            root=root.left;
          }
        }

        return res.toString().strip();
      }
  
      // Decodes your encoded data to tree.
      public TreeNode deserialize(String data) {
        if (data.length()==0) return null;
        String[] str = data.split(" ");
        Stack<TreeNode> nodes = new Stack<>();
        for (int i=str.length-1; i>=0; --i) {
          nodes.push(new TreeNode(Integer.parseInt(str[i])));
        }
        Stack<TreeNode> stack = new Stack<>();

        TreeNode root = nodes.pop();
        stack.push(root);
        while (!nodes.isEmpty()) {
          TreeNode node = nodes.pop();
          TreeNode temp = null;

          while (!stack.isEmpty() && stack.peek().val<node.val) temp=stack.pop();
          if (temp!=null) {
            temp.right=node;
            stack.push(node);
          }
          else {
            stack.peek().left = node;
            stack.push(node);
          }
        }
        return root;
      }
}