public class arrayTest03 {
  public static void main(String[] args) {
    if( args.length != 2){
      System.out.println("用户名和密码是两个哦，用空格隔开，谢谢^_^");
      return;
    }

    String username = args[0];
    String password = args[1];

    if(username.equals(args[0]) && password.equals(args[1])){
      System.out.println("被你发现大秘密了，你可以继续使用");
    }
  }
}