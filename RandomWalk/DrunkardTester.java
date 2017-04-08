/**
  DrunkardTester class
      console-based test program for Drunkard class.
      uses fixed data testing every method multiple times. 
      prints informative output including expected and actual results.  
*/
public class DrunkardTester {
    
    /**
      Test driver for Drunkard class.
      @param args not used
     */
    public static void main(String[] args){
        drunkardTest(3, 5, 2);
        
        drunkardTest(200, 200, 5);
        
        drunkardTest(340, 350, 10);
    }
    
    /**
      Test all Drunkard methods on a Drunkard with start location (x, y)
      and the size of each step.
      @param x x-coordinate of start location
      @param y y-coordinate of start location
      @param step_size the size of one step
     */
    private static void drunkardTest(int x, int y, int step_size){
        ImPoint startLocTest = new ImPoint(x, y);
        ImPoint currentLocTest;
        int stepSizeTest = step_size;
        int oldX = 0, newX = 0;
        int oldY = 0, newY = 0;
        
        System.out.println("Drunkard starts at (" + x + "," + y + "); step size is " + step_size);
        oldX = startLocTest.getX();
        oldY = startLocTest.getY();
        System.out.println("get starting loc [expected:(" + x + "," + y + ")]: " 
                           + "(" + oldX + "," + oldY + ")");
        
        Drunkard drunkardTester = new Drunkard(startLocTest, stepSizeTest);
        
        int stepTestTurn = 0;
        int TEST_NUM = 10;
        for(; stepTestTurn < TEST_NUM; stepTestTurn++){
            drunkardTester.takeStep();
            
            currentLocTest = drunkardTester.getCurrentLoc();
            newX = currentLocTest.getX();
            newY = currentLocTest.getY();
            
            if((Math.abs(newX - oldX) == step_size && Math.abs(newY - oldY) == 0)
              || (Math.abs(newY - oldY) == step_size && Math.abs(newX - oldX) == 0)){
                System.out.println("took step to (" + newX + "," + newY + ") SUCCEEDED");
            }
            else{
                System.out.println("took step to (" + newX + "," + newY 
                                   + ") FAILED: not a valid step");
            }
            oldX = newX;
            oldY = newY;
        }
        System.out.println();
    }
    
}