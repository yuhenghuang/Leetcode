class TreeNode {
  int val;
  TreeNode left;
  TreeNode right;
TreeNode(int x) { val = x; }
}

class ListNode {
  int val;
  ListNode next;
  ListNode(int x) {
    val=x;
  }
}

class LeetcodeUtil {
  public static int[] arrayIntParser(String s) {
    s = s.replaceAll("[\\[\\] \t]", "");
    String[] temp = s.split(",+");
    int[] res = new int[temp.length];
    for (int i=0; i<temp.length; ++i)
      res[i] = Integer.parseInt(temp[i]);
    return res; 
  }

  public static int[][] arrayInt2dParser(String s) {
    s = s.replaceAll("[ \t]+", "");
    String[] temp = s.split("\\],\\[");
    int dim2 = temp[0].split(",").length;
    int[][] res = new int[temp.length][dim2];
    for (int i=0; i<temp.length; ++i)
      res[i] = arrayIntParser(temp[i]);
    return res;
  }

  public static TreeNode treeParser(String s) {
    s = s.replaceAll("[\\[\\] \t]+", "");
    String[] temp = s.split(",");
    if (temp[0].length()==0) return null;
    int size = temp.length;

    TreeNode[] trees = new TreeNode[size];
    for (int i=0; i<size; ++i) {
      if (temp[i].equals("null"))
        continue;
      trees[i] = new TreeNode(Integer.parseInt(temp[i]));
    }

    for (int i=0; i<size; ++i) {
      if (trees[i]==null) continue;
      if ((i<<1)+1<temp.length)
        trees[i].left = trees[(i<<1)+1];
      if ((i<<1)+2<temp.length)
        trees[i].right = trees[(i<<1)+2];
    }
    return trees[0];
  }
}