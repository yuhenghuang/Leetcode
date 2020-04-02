import java.util.HashSet;
import java.util.Set;

class HappyNumber {
  public static void main(String[] args) {
    HappyNumber obj = new HappyNumber();
    System.out.println(obj.isHappy(19));
  }
  public boolean isHappy(int n) {
    Set<Integer> set = new HashSet<>();

    while (!set.contains(n) && n!=1) {
      set.add(n);
      String s = Integer.toString(n);
      n = 0;
      for (char c : s.toCharArray()) {
        int d = Character.getNumericValue(c);
        n += d * d;
      }
    }

    return n==1?true:false;
  }
}