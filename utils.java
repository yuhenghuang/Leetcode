import java.util.*;
import java.util.LinkedList;

class Utils {

  /**
   * Parse string to Tree
   * 
   * 
   * @param line Serialized string of a tree, e.g. "[1, NULL, 2]" white space allowed.
   * 
   * @return TreeNode* root
   */
  public static TreeNode parse_tree(String line) {
    TreeNode root = null;
    TreeNode node;
    Queue<TreeNode> queue = new LinkedList<>();

    line = line.replaceAll("[\\[\\]\\s\"]+", "");
    String[] vals = line.split(",");

    boolean left = true;
    for (String val : vals) {
      node = "null".equals(val) ? null : new TreeNode(Integer.parseInt(val));

      if (node!=null)
        queue.offer(node);

      if (root==null)
        root = node;
      else {
        if (left) 
          queue.peek().left = node;
        else
          queue.poll().right = node;
        
        left = !left;
      }
    }

    return root;
  }


  private static void print_tree_horizontal(TreeNode root, boolean left, String prefix) {
    if (root!=null) {
      System.out.println(prefix + (left ? "|-- " : "\\-- ") + root.val);
      print_tree_horizontal(root.left, true, prefix + (left ? "|   " : "    "));
      print_tree_horizontal(root.right, false, prefix + (left ? "|   " : "    "));
    }
  }


  /**
   * Print binray tree horizontally in terminal
   * 
   * 
   * @param root Root of the tree
   * 
   */
  public static void print_tree_horizontal(TreeNode root) {
    print_tree_horizontal(root, false, "");
  }


  /**
   * Split string by delimiter
   * 
   * @param str input string
   * @param delimiter delimiter
   * 
   * @return splited strings
   */
  public static String[] string_split(String str, String delimiter) {
    str = str.replaceAll("\"|\\s+", "");

    return str.split(delimiter);
  }

  /**
   * Split string by ";"
   * 
   * @param str input string
   * 
   * @return splited strings
   */
  public static String[] string_split(String str) {
    return string_split(str, ";");
  }

}
