import java.util.Scanner;
/**
   BulgarianSolitaireSimulator class
     contains the main routine.
     reads in user input to decide simulator mode.
     prints out the simulator procedure in detail.
     prompts for the initial configuration from the user if -u mode is enabled.
     error-checks user configuration and prints out corresponding information.
     stops between every round of the game if -s mode is enabled.
 */

public class BulgarianSolitaireSimulator {
    
    /**
       Simulator class for Bulgarian Solitaire.
       @param args deciding running mode of the program
     */
    public static void main(String[] args) {

        boolean singleStep = false;
        boolean userConfig = false;

        for (int i = 0; i < args.length; i++) {
            if (args[i].equals("-u")) {
                userConfig = true;
            }
            else if (args[i].equals("-s")) {
                singleStep = true;
            }
        }

        // <add code here>
        SolitaireBoard solitaireBoard = constructBoard(userConfig);
        printResult(solitaireBoard, singleStep);
    }
    
    // <add private static methods here>
    /**
       Construct a new Solitaire Board.
       @param userConfiguration whether to prompt for the initial configuration from the user
       @return a SolitaireBoard object representing the initial configuration 
     */
    private static SolitaireBoard constructBoard(boolean userConfiguration) {
        Scanner in = new Scanner(System.in);
                
        if(!userConfiguration) { // -u mode is disabled
            return new SolitaireBoard();
        }
        else { // -u mode is enabled
            System.out.println("Number of total cards is " + SolitaireBoard.CARD_TOTAL);
            System.out.println(
                    "You will be entering the initial configuration of the cards (i.e., how many in each pile).");
            System.out.println(
                    "Please enter a space-separated list of positive integers followed by newline:");
                    
            String userConfigStr = in.nextLine();
            while(!SolitaireBoard.isValidConfigString(userConfigStr)) {
                System.out.println(
                    "ERROR: Each pile must have at least one card and the total number of cards must be 45");
                System.out.println(
                        "Please enter a space-separated list of positive integers followed by newline:");
                userConfigStr = in.nextLine();
            }
            return new SolitaireBoard(userConfigStr);
        }
    }
    
    /**
       Print out the procedure of simulator.
       @param board the initial Solitaire Board to play the game
       @param diaplayByStep whether to stop between every round of the game
     */
    private static void printResult(SolitaireBoard board, boolean diaplayByStep) {
        System.out.println("Initial configuration: " + board.configString());
        
        int roundNum = 1;
        while(!board.isDone()) {
            board.playRound();
            System.out.println("[" + roundNum +"] Current configuration: "
                                   + board.configString());
            roundNum++;
            
            if(diaplayByStep) { // -s mode is enabled
                System.out.print("<Type return to continue>");
                new Scanner(System.in).nextLine(); // wait for return to continue
            }
        }
        System.out.println("Done!");
    }
}