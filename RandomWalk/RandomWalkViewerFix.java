import javax.swing.JFrame;

public class RandomWalkViewerFix {
	public static void main(String[] args){
		int[] drawPointX = new int[1001];
		int[] drawPointY = new int[1001];
		
		ImPoint startLoc = new ImPoint(200, 200);
		ImPoint currentLoc;
		int stepSize = 5;
		Drunkard drunkard = new Drunkard(startLoc, stepSize);
		int oldX = 0, oldY = 0;
		int newX = 0, newY = 0;
		
		currentLoc = drunkard.getCurrentLoc();
		oldX = currentLoc.getX();
		oldY = currentLoc.getY();
		drawPointX[0] = oldX;
		drawPointY[0] = oldY;
	
		drunkard.takeStep();
		currentLoc = drunkard.getCurrentLoc();
		newX = currentLoc.getX();
		newY = currentLoc.getY();
	
		int i = 1;
		for(; i <= 1000; i++) {
			oldX = newX;
			oldY = newY;
			drawPointX[i] = oldX;
			drawPointY[i] = oldY;
			drunkard.takeStep();
			currentLoc = drunkard.getCurrentLoc();
			newX = currentLoc.getX();
			newY = currentLoc.getY();
		}
		
		
		JFrame frame = new JFrame();
		
		frame.setSize(400, 400);
		frame.setTitle("RandomWalk");
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		RandomWalkComponentFix component = new RandomWalkComponentFix(drawPointX, drawPointY);
		frame.add(component);
		frame.setVisible(true);		
	}
}