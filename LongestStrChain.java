import java.util.Map;
import java.util.HashMap;
import java.util.Arrays;

public class LongestStrChain {
  public static void main(String[] args) {
    LongestStrChain obj = new LongestStrChain();
    System.out.println(obj.longestStrChain(new String[] {"ksqvsyq","ks","kss","czvh","zczpzvdhx","zczpzvh","zczpzvhx","zcpzvh","zczvh","gr","grukmj","ksqvsq","gruj","kssq","ksqsq","grukkmj","grukj","zczpzfvdhx","gru"}));
  }

  Map<String, Integer> map;
  public int longestStrChain(String[] words) {
    map = new HashMap<>();
    for (String s : words)
      map.put(s, 0);
    
    for (String s : words)
      dfs(s);

    int res=0;
    for (int val : map.values())
      if (val>res)
        res=val;
    return res;
  }

  private int dfs(String s) {
    int res=map.get(s);
    if (res>0) return res;
    res=1;
    for (int i=0; i<s.length(); ++i) {
      String sNew = s.substring(0, i) + s.substring(i+1);
      if (map.containsKey(sNew))
        res=Math.max(res, dfs(sNew)+1);
    }
    map.put(s, res);
    return res;
  }


  public int longestStrChainOn2(String[] words) {
    int n = words.length;
    if (n==0) return 0;
    Arrays.sort(words, (a,b) -> a.length()-b.length());
    int[] dp = new int[n];
    for (int i=0; i<n; i++) {
      String s=words[i];
      int res=1, l=s.length();
      for (int j=i-1; j>=0; --j) 
        if (words[j].length()==l-1)
          for (int k=0; k<l; k++) {
            String sNew = s.substring(0, k) + s.substring(k+1);
            if (sNew.equals(words[j])) {
              System.out.println(i+" "+sNew);
              res=Math.max(res, 1+dp[j]);
              //break;
            }
          }
      dp[i]=res;
    }

    int ans=1;
    for (int i=0; i<n; i++)
      if (dp[i]>ans)
        ans=dp[i];
    return ans;
  }
}