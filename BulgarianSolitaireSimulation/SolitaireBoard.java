import java.util.Random;
import java.util.Scanner;
/*
   class SolitaireBoard
   The board for Bulgarian Solitaire.  You can change what the total number of cards is for the game
   by changing NUM_FINAL_PILES, below.  Don't change CARD_TOTAL directly, because there are only some values
   for CARD_TOTAL that result in a game that terminates.
   (See comments below next to named constant declarations for more details on this.)
 */


public class SolitaireBoard {
   
    public static final int NUM_FINAL_PILES = 9;
    // number of piles in a final configuration
    // (note: if NUM_FINAL_PILES is 9, then CARD_TOTAL below will be 45)

    public static final int CARD_TOTAL = NUM_FINAL_PILES * (NUM_FINAL_PILES + 1) / 2;
    // bulgarian solitaire only terminates if CARD_TOTAL is a triangular number.
    // see: http://en.wikipedia.org/wiki/Bulgarian_solitaire for more details
    // the above formula is the closed form for 1 + 2 + 3 + . . . + NUM_FINAL_PILES

    private static final int ONE_PILE = 1;
    
    
    /**
      Representation invariant:
      -- the total number in Solitaire Board is CARD_TOTAL(a triangular number)
      -- each pile in Solitaire Board must have at least one card, 
         and at most CARD_TOTAL cards
      -- in the end, there are NUM_FINAL_PILES piles that are of sizes 1, 2, 
         3, . . . , NUM_FINAL_PILES, in any order
      -- there are at least one pile and at most CARD_TOTAL piles
      -- pileNum is the number of piles 
      -- 1 <= pileNum <= CARD_TOTAL
     */

    // <add instance variables here>
    private int[] solitairBoard = new int[CARD_TOTAL];
    private int pileNum;

    /**
     Creates a solitaire board with the given configuration.
     PRE: SolitaireBoard.isValidConfigString(numberString)
     */
    public SolitaireBoard(String numberString) {
        solitairBoard = stringToArrayNumber(numberString);
        pileNum = countPileNum(solitairBoard);

        assert isValidSolitaireBoard();   
    }

    
    /**
      Creates a solitaire board with a random initial configuration.
     */
    public SolitaireBoard() {
        Random pileRan = new Random();
        int NUM_ADJUST = 1; // adjust the random integer starting from 1
        pileNum = pileRan.nextInt(CARD_TOTAL) + NUM_ADJUST;
        int remainingCard = 45;
        int pileNumRe = pileNum - ONE_PILE;
        
        for(int i = 0; i < pileNum - ONE_PILE; i++) {
            solitairBoard[i] = pileRan.nextInt(remainingCard - pileNumRe) + NUM_ADJUST;
            remainingCard -= solitairBoard[i];
            pileNumRe--;
        }
        solitairBoard[pileNum - ONE_PILE] = remainingCard;
        
        assert isValidSolitaireBoard();
    }

    
    /**
      Plays one round of Bulgarian solitaire.  Updates the configuration according to the rules
      of Bulgarian solitaire: Takes one card from each pile, and puts them all together in a new pile.
      The old piles that are left will be in the same relative order as before, 
      and the new pile will be at the end.
     */
    public void playRound() {
        for(int i = 0; i < pileNum; i++) {
            solitairBoard[i]--;
        }
        
        // after one round, if one pile gets to 0, count the number;
        // if one pile is not 0, move this pile to the left by countZero piles.
        int countZero = 0;
        for(int i = 0; i < pileNum; i++) {
            if(solitairBoard[i] == 0) {
                countZero++;
            }
            else {
                solitairBoard[i - countZero] = solitairBoard[i];
            }            
        }
        
        for(int i = countZero; i > 0; i--) {
            solitairBoard[pileNum - i] = 0;
        }

        solitairBoard[pileNum - countZero] = pileNum;
        pileNum = pileNum - countZero + ONE_PILE;
        
        assert isValidSolitaireBoard();
    }

    
    /**
      Returns true iff the current board is at the end of the game.  That is, there are NUM_FINAL_PILES
      piles that are of sizes 1, 2, 3, . . . , NUM_FINAL_PILES, in any order.
     */
    public boolean isDone() {
        if(pileNum != NUM_FINAL_PILES) { return false; }
        
        // if there are i cards in one pile, the value of element with index 
        // (i-1) in the new array adds by one. If the current board is at the 
        // end of the game, all the valus in the new array are exactly one,
        // illustrating there are exactly NUM_FINAL_PILES piles with sizes 
        // 1, 2, 3, ..., NUM_FINAL_PILES.
        int[] sortedPile = new int[NUM_FINAL_PILES];
        for(int i = 0; i < NUM_FINAL_PILES; i++) {
            if(solitairBoard[i] <= NUM_FINAL_PILES) {
                sortedPile[solitairBoard[i] - 1]++;
            }
        }
        
        int numCount = 0;
        for(int i = 0; i < NUM_FINAL_PILES; i++) {
            if(sortedPile[i] == 1) { numCount++; }
        }
        
        if(numCount == NUM_FINAL_PILES) {
            return true;
        }
        else {
            return false;
        }
    }

    
    /**
      Returns current board configuration as a string with the format of
      a space-separated list of numbers with no leading or trailing spaces.
      The numbers represent the number of cards in each non-empty pile.
     */
    public String configString() {
        String currentConfig = new String();
        
        for(int i = 0; i < pileNum - ONE_PILE; i++) {
            currentConfig += solitairBoard[i] + " "; 
        }
        currentConfig += solitairBoard[pileNum - ONE_PILE];
        
        assert isValidSolitaireBoard();
        return currentConfig;     
    }


    /**
      Returns true iff configString is a space-separated list of numbers that
      is a valid Bulgarian solitaire board with card total SolitaireBoard.CARD_TOTAL
     */
    public static boolean isValidConfigString(String configString) {
        // check there are only number and space in the string
        for(int i = 0; i < configString.length(); i++) {
            int checkBit = configString.charAt(i);
            if(checkBit < '0' || checkBit > '9') {
                if(checkBit != ' ') { return false; }
            }
        }
        
        int[] checkPiles = stringToArrayNumber(configString);
        int checkPilesNum = countStrPileNum(configString);
        
        if(checkPilesNum > CARD_TOTAL) { return false; }
                
        return isValidConfiguration(checkPiles, checkPilesNum);
    }


    /**
      Returns true iff the solitaire board data is in a valid state
      (See representation invariant comment for more details.)
     */
    private boolean isValidSolitaireBoard() {

        return isValidConfiguration(solitairBoard, pileNum);  

    }


    // <add any additional private methods here>
    /**
       Convert a String into an array of numbers.
       @param  stringInput the String to be converted
       @return an integer array representing the solitaire board data
     */
    private static int[] stringToArrayNumber(String stringInput) {
        Scanner originalStr = new Scanner(stringInput);
        int[] arrayNumber = new int[CARD_TOTAL];
        
        arrayNumber[0] = originalStr.nextInt();
        int i = 1;
        while(originalStr.hasNext() && i < CARD_TOTAL){
            arrayNumber[i] = originalStr.nextInt();
            i++;
        }
        return arrayNumber;
    }
  
    /**
       Count the number of non-zero integer in an array, 
       that is the number of piles.
       @param countObject the array to be counted
       @return an integer representing the number of piles
     */
    private static int countPileNum(int[] countObject) {
        int count = 0;
        for(int i = 0; i < CARD_TOTAL; i++) {
            if(countObject[i] != 0) { count++; }
        }
        return count;
    }
    
    /**
       Count the number of non-zero integer in a string, 
       that is the number of piles inputed by user.
       @param countString the string to be counted
       @return an integer representing the number of piles
     */
    private static int countStrPileNum(String countString) {
        Scanner countStr = new Scanner(countString);
        int count = 0;
        while(countStr.hasNextInt()) {
            countStr.nextInt();
            count++;
        }
        return count;
    }
    
    /**
       Check the solitaire board data is in a valid state.
       @param piles the solitaire board to be checked
       @param numPiles the number of piles in the solitaire board
       @return true or false whether the solitaire board data is in a valid state
     */
    private static boolean isValidConfiguration(int[] piles, int numPiles) {
        int countTotal = 0;
        for(int i = 0; i < numPiles; i++) {
            if(piles[i] <= 0) { return false; }
            countTotal +=piles[i]; 
        }
        if(countTotal != CARD_TOTAL) { return false; }
        return true;
    }
}