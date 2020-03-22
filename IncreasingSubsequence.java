import java.util.*;

public class IncreasingSubsequence {
  public static void main(String[] args) {
    IncreasingSubsequence obj = new IncreasingSubsequence();
    System.out.println(obj.findSubsequences(new int[] {4,6,7,7,6,2,3,1,7}));
  }

  Stack<Integer> stack;
  List<List<Integer>> res;
  public List<List<Integer>> findSubsequences(int[] nums) {
    res = new ArrayList<>();
    stack = new Stack<>();
    dfs(0, nums);
    return res;
  }

  private void dfs(int idx, int[] nums) {
    if (stack.size()>1) res.add(new ArrayList<>(stack));

    //for unique results
    Set<Integer> visited = new HashSet<>();
    for (int i=idx; i<nums.length; ++i) 
      if (!visited.contains(nums[i]) && (stack.size()==0 || stack.peek()<=nums[i])) {
        visited.add(nums[i]);
        stack.push(nums[i]);
        dfs(i+1, nums);
        stack.pop();
      }
  }
}