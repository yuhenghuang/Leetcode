import java.util.ArrayList;
import java.util.List;


class FlipToPreorder_Fast {
  List<Integer> res;
  int[] voyage;
  int idx;
  boolean poss;
  public List<Integer> flipMatchVoyage(TreeNode root, int[] voyage) {
    res = new ArrayList<>();
    this.voyage = voyage;
    idx = 0;
    poss = true;
    dfs(root);
    return poss?res:new ArrayList<>(List.of(-1));
  }

  private void dfs(TreeNode node) {
    if (!poss) return;
    if (node!=null) {
      if (node.val!=voyage[idx++]) {
        poss=false;
        return;
      }
      if (idx<voyage.length && node.left!=null && node.left.val!=voyage[idx]) {
        res.add(node.val);
        dfs(node.right);
        dfs(node.left);
      }
      else {
        dfs(node.left);
        dfs(node.right);
      }
    }
  }
}



class FlitToPreorder {
  List<Integer> res;
  int[] preorder;
  public List<Integer> flipMatchVoyage(TreeNode root, int[] voyage) {
    res = new ArrayList<>();
    preorder = voyage;
    return dfs(root, 0, preorder.length-1)?res:new ArrayList<>(List.of(-1));
  }

  private boolean dfs(TreeNode node, int i, int j) {
    if (node==null) return false;
    if (i==j) 
      if (node.left==null && node.right==null) return true;
      else return false;
    if (node.val!=preorder[i] || (node.left==null && node.right==null)) return false;

    boolean poss=false;
    if (node.left!=null && node.right!=null) {
      int k=i+1;
      if (node.left.val==preorder[i+1]) {
        for (k=i+1; k<=j; ++k)
          if (preorder[k]==node.right.val)
            break;
        
        if (preorder[k]!=node.right.val) return false;
        poss = dfs(node.left, i+1, k-1) && dfs(node.right, k, j);
      }
      else if (node.right.val==preorder[i+1]) {
        for (k=i+1; k<=j; ++k)
        if (preorder[k]==node.left.val)
          break;
      
      if (preorder[k]!=node.left.val) return false;
      poss = dfs(node.right, i+1, k-1) && dfs(node.left, k, j);
      if (poss) res.add(node.val);
      }
    }
    else {
      TreeNode next = node.left!=null?node.left:node.right;
      if (next.val==preorder[i+1]) {
        poss = dfs(next, i+1, j);
      }
    }
    return poss;
  }
}