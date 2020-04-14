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

class LeetcodeParser {
  public static int[] arrayParser(String s) {
    s = s.replaceAll("[\\[\\]]", "");
    String[] temp = s.split("[ ,]+");
    int[] res = new int[temp.length];
    for (int i=0; i<temp.length; ++i)
      res[i] = Integer.parseInt(temp[i]);
    return res; 
  }

  public static int[][] array2dParser(String s) {
    s = s.replaceAll("[ ]+", "");
    String[] temp = s.split("\\],\\[");
    int dim2 = temp[0].split(",").length;
    int[][] res = new int[temp.length][dim2];
    for (int i=0; i<temp.length; ++i)
      res[i] = arrayParser(temp[i]);
    return res;
  }
}