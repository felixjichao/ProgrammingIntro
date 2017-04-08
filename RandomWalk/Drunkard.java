import java.util.Random;
/**
   Drunkard class
       Represents a "drunkard" doing a random walk on a grid.
*/
public class Drunkard {

    // add private instance variables here:
    private ImPoint currentLoc;
    private int STEP_SIZE;
    private Random generator;
    private int moveDirection;

    /**
       Creates drunkard with given starting location and distance
       to move in a single step.
       @param startLoc starting location of drunkard
       @param theStepSize size of one step in the random walk
    */
    public Drunkard(ImPoint startLoc, int theStepSize) {
        currentLoc = new ImPoint(0, 0);
        currentLoc = startLoc;
        STEP_SIZE = theStepSize;
    }

    /**
       Takes a step of length step-size (see constructor) in one of
       the four compass directions.  Changes the current location of the
       drunkard.
    */
    public void takeStep() {
        generator = new Random();
        // get a random number from 0 to 4, each representing a compass direction
        moveDirection = generator.nextInt(4);
        switch(moveDirection){
        case 0:  // move to the NORTH
            currentLoc = currentLoc.translate(0, -STEP_SIZE);
            break;
        case 1:  // move to the EAST
            currentLoc = currentLoc.translate(STEP_SIZE, 0);
            break;          
        case 2:  // move to the SOUTH
            currentLoc = currentLoc.translate(0, STEP_SIZE);
            break;
        default:  // move to the WEST
            currentLoc = currentLoc.translate(-STEP_SIZE, 0);
            break;
        }
    }

    /**
       gets the current location of the drunkard.
       @return an ImPoint object representing drunkard's current location
    */
    public ImPoint getCurrentLoc() {
        return currentLoc;
    }
}