class DetectCapital {
  public static void main(String[] args) {
    DetectCapital obj = new DetectCapital();
    System.out.println(obj.detectCapitalUse("FlaG"));
  }
  public boolean detectCapitalUse(String word) {
    return allUpper(word) || allLower(word) || firstUpper(word);
  }

  boolean allUpper(String w) {
    for (int i=0; i<w.length(); ++i)
      if (Character.isLowerCase(w.charAt(i)))
        return false;
    return true;
  }

  boolean allLower(String w) {
    for (int i=0; i<w.length(); ++i)
      if (Character.isUpperCase(w.charAt(i)))
        return false;
    return true;
  }

  boolean firstUpper(String w) {
    return Character.isUpperCase(w.charAt(0)) && allLower(w.substring(1));
  }
}