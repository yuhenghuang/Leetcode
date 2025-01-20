import java.util.Scanner;

class RobotBoundInCircle {
  public static void main(String[] args) {
    RobotBoundInCircle obj = new RobotBoundInCircle();
    Scanner sc = new Scanner(System.in);
    String instructions;
    
    while (sc.hasNextLine()) {
      instructions = sc.nextLine();
      System.out.println(obj.isRobotBounded(instructions));
    }

    sc.close();
  }
  public boolean isRobotBounded(String instructions) {
    int[][] steer = new int[][] {{0,1}, {1,0}, {0,-1}, {-1,0}};
    
    int x=0, y=0, dir=0, n=instructions.length();

    for (int i=0; i<n; ++i) {
      switch (instructions.charAt(i)) {
        case 'L':
          dir = (dir+3) % 4;
          break;
        case 'R':
          dir = (dir+1) % 4;
          break;
        case 'G':
          x += steer[dir][0];
          y += steer[dir][1];
          break;
        default:
          break;
      }
    }

    return (dir!=0) || (x==0 && y==0);
  }
}
