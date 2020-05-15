class FinalizeTest {
  public static void main(String[] args) {

    while(Person.flag) {
      // Person p = new Person();
      // p = null;
    }
    
  }
}

class Person {
  Person() {
    // System.out.println("wtf!");
  }
  static boolean flag = true;
  @Override
  protected void finalize() {
    System.out.println("omae wa mou shindeiru");
    flag = false;
  }
}