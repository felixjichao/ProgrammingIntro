import java.awt.*;
import java.awt.geom.Line2D;
import java.awt.geom.Point2D;
import java.util.ListIterator;
import javax.swing.JComponent;

/**
 MazeComponent class

 A component that displays the maze and path through it if one has been found.
 */
public class MazeComponent extends JComponent
{
    private Maze maze;

    private static final int START_X = 10; // where to start drawing maze in frame
    private static final int START_Y = 10;
    private static final int BOX_WIDTH = 20;  // width and height of one maze unit
    private static final int BOX_HEIGHT = 20;
    private static final int INSET = 2;
    // how much smaller on each side to make entry/exit inner box


    /**
     Constructs the component.
     @param maze   the maze to display
     */
    public MazeComponent(Maze maze)
    {
        this.maze = maze;
    }


    /**
     Draws the current state of maze including the path through it if one has
     been found.
     @param g the graphics context
     */
    public void paintComponent(Graphics g) {
        Graphics2D g2 = (Graphics2D) g;

        // Draw the outside frame
        Rectangle frame = new Rectangle(START_X, START_Y,
                BOX_WIDTH * maze.numCols(),
                BOX_HEIGHT * maze.numRows());
        g2.draw(frame);

        // Draw all the walls
        for (int i = 0; i < maze.numRows(); i++) {
            for (int j = 0; j < maze.numCols(); j++) {
                if (maze.hasWallAt(new MazeCoord(i, j))) {
                    Rectangle wall = new Rectangle(START_X + j * BOX_WIDTH,
                            START_Y + i * BOX_HEIGHT,
                            BOX_WIDTH, BOX_HEIGHT);
                    g2.setColor(Color.BLACK);
                    g2.fill(wall);
                }
            }
        }

        // Draw the entry location block
        Rectangle start =
                new Rectangle(START_X + maze.getEntryLoc().getCol() * BOX_WIDTH + INSET,
                        START_Y + maze.getEntryLoc().getRow() * BOX_HEIGHT + INSET,
                        BOX_WIDTH - INSET - INSET, BOX_HEIGHT - INSET - INSET);
        g2.setColor(Color.YELLOW);
        g2.fill(start);

        // Draw the exit location block
        Rectangle end =
                new Rectangle(START_X + maze.getExitLoc().getCol() * BOX_WIDTH + INSET,
                        START_Y + maze.getExitLoc().getRow() * BOX_HEIGHT + INSET,
                        BOX_WIDTH - INSET - INSET, BOX_HEIGHT - INSET - INSET);
        g2.setColor(Color.GREEN);
        g2.fill(end);

        // Draw the path from entry to exit if existing
        if(maze.getPath().size() > 0) {
            ListIterator<MazeCoord> iter = maze.getPath().listIterator();
            MazeCoord from = iter.next();
            MazeCoord to = iter.next();

            Point2D.Double fromPoint = new Point2D.Double(
                    BOX_WIDTH + BOX_WIDTH * from.getCol(),
                    BOX_HEIGHT + BOX_HEIGHT * from.getRow());
            Point2D.Double toPoint = new Point2D.Double(
                    BOX_WIDTH + BOX_WIDTH * to.getCol(),
                    BOX_HEIGHT + BOX_HEIGHT * to.getRow());
            Line2D.Double segment = new Line2D.Double(fromPoint, toPoint);

            g2.setColor(Color.BLUE);
            g2.draw(segment);

            for (int k = 2; k < maze.getPath().size(); k++) {
                from = to;
                to = iter.next();

                fromPoint = new Point2D.Double(
                        BOX_WIDTH + BOX_WIDTH * from.getCol(),
                        BOX_HEIGHT + BOX_HEIGHT * from.getRow());
                toPoint = new Point2D.Double(
                        BOX_WIDTH + BOX_WIDTH * to.getCol(),
                        BOX_HEIGHT + BOX_HEIGHT * to.getRow());
                segment = new Line2D.Double(fromPoint, toPoint);

                g2.draw(segment);
            }

        }
    }
}


