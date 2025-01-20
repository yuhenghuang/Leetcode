import java.util.*;


public class Permutations{
    public static void main(String[] args) {
        int[] nums = {1,2,3};
        Solution solution = new Solution();
        System.out.println(solution.permute(nums));
    }
}


class Solution {
    public List<List<Integer>> res = new ArrayList<>();
    public boolean[] memo;
    public int[] nums;

    public List<List<Integer>> permute(int[] nums) {
        this.nums=nums;
        this.memo= new boolean[nums.length];
        dfs(new ArrayList<Integer>());
        return res;
    }

    public void dfs(List<Integer> cur){
        if (cur.size()==nums.length) {
            res.add(new ArrayList<>(cur));
            return ;
        }

        for (int i=0; i<nums.length; i++) {
            if (memo[i]==false) {
                cur.add(nums[i]);
                memo[i]=true;
                dfs(cur);
                cur.remove(cur.size()-1);
                memo[i]=false;
            }
        }
    }
}