import java.util.*;

class TreeNode {
  int val;
  TreeNode left;
  TreeNode right;
  TreeNode() {}
  TreeNode(int x) { val = x; }
  TreeNode(int val, TreeNode left, TreeNode right) {
    this.val = val;
    this.left = left;
    this.right = right;
  }
}

class ListNode {
  int val;
  ListNode next;
  ListNode(int x) {
    val=x;
  }
}

class LeetcodeUtil {
  public static String[] arrayStringParser(String s) {
    s = s.replaceAll("[\\[\\] \t]", "");
    return s.split(",");
  }

  public static List<String> listStringParser(String s) {
    String[] temp = arrayStringParser(s);
    List<String> res = new ArrayList<>();
    for (String e : temp)
      res.add(e);
    return res;
  }

  public static int[] arrayIntParser(String s) {
    String[] temp = arrayStringParser(s);
    int[] res = new int[temp.length];
    if (temp.length==1 && temp[0].length()==0)
      return res;
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

  public static List<Integer> listIntParser(String s) {
    String[] temp = arrayStringParser(s);
    List<Integer> res = new ArrayList<>();
    if (temp.length==1 && temp[0].length()==0)
      return res;
    for(int i=0; i<temp.length; ++i)
      res.add(Integer.parseInt(temp[i]));
    return res;
  }

  public static List<List<Integer>> listInt2dParser(String s) {
    s = s.replaceAll("[ \t]+", "");
    String[] temp = s.split("\\],\\[");
    List<List<Integer>> res = new ArrayList<>();
    for (int i=0; i<temp.length; ++i)
      res.add(listIntParser(temp[i]));
    return res;
  }

  private static TreeNode treeParserHelper(int i, String[] arr) {
    if (i>=arr.length || arr[i].equals("null")) return null;
    TreeNode node = new TreeNode(Integer.parseInt(arr[i]));
    node.left = treeParserHelper(i*2+1, arr);
    node.right = treeParserHelper(i*2+2, arr);
    return node;
  }

  public static TreeNode treeParser(String s) {
    String[] temp = arrayStringParser(s);
    if (temp[0].length()==0) return null;
    return treeParserHelper(0, temp);
  }
}