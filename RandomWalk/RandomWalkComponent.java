import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.geom.Line2D;
import java.awt.geom.Point2D;
import javax.swing.JComponent;

/**
  RandomWalkComponent class
      contains a constructor that initializes the amount of steps.
      overrides paintComponent to draw the random walk.
      uses a Drunkard object to keep track of the current state of drunkard.  
*/
public class RandomWalkComponent extends JComponent {
    private int STEP_AMOUNT;
    private int THE_STEP_SIZE = 5;
    private int oldX, oldY;
    private int newX, newY;
    private int stepCount;
    
    /**
      Constructs a RandomWalkComponet with desired number of steps.
    */  
    public RandomWalkComponent(int step){
        STEP_AMOUNT = step;
    }
    
    /**
      Keep track of the current state of drunkard, 
      and draw the random walk.  
      @param g the graphics context
    */
    public void paintComponent(Graphics g){
        Graphics2D g2 = (Graphics2D) g;
        oldX = 0;
        oldY = 0;
        newX = 0;
        newY = 0;
        stepCount = 1;
        
        // set the start location in the middle of the grid
        ImPoint startLoc = new ImPoint(200, 200);
        ImPoint currentLoc;

        Drunkard drunkard = new Drunkard(startLoc, THE_STEP_SIZE);
        currentLoc = drunkard.getCurrentLoc();
        oldX = currentLoc.getX();
        oldY = currentLoc.getY();
        Point2D.Double from = new Point2D.Double(oldX, oldY);
        
        drunkard.takeStep();
        currentLoc = drunkard.getCurrentLoc();
        newX = currentLoc.getX();
        newY = currentLoc.getY();
        Point2D.Double to = new Point2D.Double(newX, newY);
        
        // draw the first step
        Line2D.Double segment = new Line2D.Double(from, to);
        g2.draw(segment);
        
        // draw one step at each iteration
        for(; stepCount <= STEP_AMOUNT; stepCount++) {
            oldX = newX;
            oldY = newY;
            from = new Point2D.Double(oldX, oldY);
            
            drunkard.takeStep();
            currentLoc = drunkard.getCurrentLoc();
            newX = currentLoc.getX();
            newY = currentLoc.getY();
            to = new Point2D.Double(newX, newY);
            
            segment = new Line2D.Double(from, to);
            g2.draw(segment);
        }
    }
}