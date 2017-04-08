public class MazeTester {
    public static void main(String[] args) {
        boolean[][] test =
        {
            {true, false, false, false},
            {false, true, false, false},
            {false, false, false, true},
            {false, true, true, false},
        };
        MazeCoord startTest = new MazeCoord(3,0);
        MazeCoord endTest = new MazeCoord(3,3);

        Maze testCoord = new Maze(test, startTest, endTest);
        int rowTest = testCoord.numRows();
        int colTest = testCoord.numCols();

        MazeCoord start = testCoord.getEntryLoc();
        MazeCoord end = testCoord.getExitLoc();

        boolean wall1 = testCoord.hasWallAt(new MazeCoord(1,1));
        boolean wall2 = testCoord.hasWallAt(new MazeCoord(0,2));
        boolean wall3 = testCoord.hasWallAt(new MazeCoord(2,0));

        System.out.println(rowTest + " " + colTest + start.toString() + end.toString() + wall1 + wall2 + wall3);

        System.out.print(testCoord.search());
    }
}