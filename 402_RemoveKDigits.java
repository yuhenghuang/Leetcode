import java.util.ArrayDeque;
import java.util.Deque;

class RemoveKDights {
  public String removeKdigits(String num, int k) {
    Deque<Character> dq = new ArrayDeque<>();
    dq.offerLast('0');
    for (char c : num.toCharArray()) {
      while (k>0 && !dq.isEmpty() && dq.peekLast()>c) {
        dq.pollLast();
        --k;
      }
      dq.offerLast(c);
    }
    StringBuffer sb = new StringBuffer("");
    while (k-->0)
      dq.pollLast();
    while (dq.size()>1 && dq.peekFirst()=='0')
      dq.pollFirst();
    while (!dq.isEmpty())
      sb.append(dq.pollFirst());
    return sb.toString();
  }
}