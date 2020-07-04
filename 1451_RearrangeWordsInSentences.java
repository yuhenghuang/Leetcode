import java.util.Arrays;
import java.util.Comparator;

class RearrangeWordsInSentences {
  public static void main(String[] args) {
    RearrangeWordsInSentences obj = new RearrangeWordsInSentences();
    System.out.println(obj.arrangeWords("To be or not to be"));
  }
  class SortByLength implements Comparator<String> {
    @Override
    public int compare(String a, String b) {
      return a.length() - b.length();
    }
  }

  public String arrangeWords(String text) {
    String[] arr = text.split("\s");
    arr[0] = arr[0].toLowerCase();

    Arrays.sort(arr, new SortByLength());
    String res = String.join("\s", arr);
    return Character.toUpperCase(res.charAt(0)) + res.substring(1);
  }
}