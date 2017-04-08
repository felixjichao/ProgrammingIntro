import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.geom.Line2D;
import java.awt.geom.Point2D;
import javax.swing.JComponent;


public class RandomWalkComponentFix extends JComponent {
	private int[] drawPX;
	private int[] drawPY;
	 
	public RandomWalkComponentFix(int[] drawX, int[] drawY){
		drawPX = new int[1001];
		drawPY = new int[1001];
		System.arraycopy(drawX, 0, drawPX, 0, 1001);
		System.arraycopy(drawY, 0, drawPY, 0, 1001);
	}
	public void paintComponent(Graphics g){
		Graphics2D g2 = (Graphics2D) g;
		
		for(int i = 0; i <= 999; i++){
			Point2D.Double from = new Point2D.Double(drawPX[i], drawPY[i]);
			Point2D.Double to = new Point2D.Double(drawPX[i+1], drawPY[i+1]);
			
			Line2D.Double segment = new Line2D.Double(from, to);
		
			g2.draw(segment);
		//drawSegment = true;
		}
	}
}