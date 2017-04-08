import javax.swing.JFrame;
import java.util.Scanner;

/**
  RandomWalkViewer class
      contains the main routine.
      prompts for the number of steps.
      creates the JFrame containing the RandomWalkComponet.  
*/
public class RandomWalkViewer {
    
    /**
      The main routine for RandomWalkViewer class.
      @param args not used
    */
    public static void main(String[] args){
        int STEP_NUM;
        Scanner in = new Scanner(System.in);
        System.out.print("Enter number of steps: ");
        STEP_NUM = in.nextInt();
        in.nextLine();
        while(STEP_NUM <= 0){
            System.out.println("ERROR: Number entered must be greater than 0.");
            System.out.print("Enter number of steps: ");
            STEP_NUM = in.nextInt();
            in.nextLine();
        }
        
        JFrame frame = new JFrame();
        
        frame.setSize(400, 400);
        frame.setTitle("RandomWalk");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        
        RandomWalkComponent component = new RandomWalkComponent(STEP_NUM);
        frame.add(component);
        frame.setVisible(true);
        in.close();
    }
}