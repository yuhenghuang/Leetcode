import java.util.Stack;

public class AsteroidCollision {
    public int[] asteroidCollision(int[] asteroids) {
        Stack<Integer> stack = new Stack<>();

        for (int weight : asteroids) {
            while (!stack.empty() && (stack.peek()>0 && weight<0)) {
                weight=stack.peek()+weight>0?stack.peek():stack.peek()+weight<0?weight:0;
                stack.pop();
            }
            if (weight!=0) stack.push(weight);
        }

        int[] res= new int[stack.size()];
        for (int i=stack.size()-1; i>=0; i--) {
            res[i]=stack.pop();
        }
        return res;
    }
}