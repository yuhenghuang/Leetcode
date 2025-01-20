import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.Scanner;

class InsertIntoBST {
  public static void main(String[] args) {
    InsertIntoBST obj = new InsertIntoBST();

    FileInputStream f = null;
    Scanner sc = null;
    try {
      f = new FileInputStream("Inputs/701_InsertIntoBST.txt");
      sc = new Scanner(f);

      while (sc.hasNextLine()) {
        String line = sc.nextLine();
        String[] params = Utils.string_split(line);

        TreeNode root = Utils.parse_tree(params[0]);
        int val = Integer.parseInt(params[1]);

        Utils.print_tree_horizontal(obj.insertIntoBST(root, val));
      }
    }
    catch (FileNotFoundException e) { }
    finally {
      if (sc!=null) sc.close();

      /*
      if (f!=null)
        try {
          f.close();
        }
        catch (IOException e) { }
      */
    }
  }
  public TreeNode insertIntoBST(TreeNode root, int val) {
    if (root==null) {
      return new TreeNode(val);
    }
    else if (root.val>val) {
      root.left = insertIntoBST(root.left, val);
    }
    else if (root.val<val) {
      root.right = insertIntoBST(root.right, val);
    }

    return root;
  }
}
