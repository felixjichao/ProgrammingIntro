import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.Random;

public class RandomTextGenerator {
    private Map<Integer,String> sourceWords;
    private int prefixLength;
    private int sourceLength;
    private ArrayList<String> prefix;
    private Map<Prefix, ArrayList<String>> prefSucc;
    private Random ranGen;
    private boolean debugMode;

    public RandomTextGenerator(Map<Integer,String> sourceWords,
                               int prefixLength, boolean debugMode) {
        this.sourceWords = sourceWords;
        sourceLength = sourceWords.size();
        this.prefixLength = prefixLength;
        prefix = new ArrayList<String>(prefixLength);
        this.debugMode = debugMode;
        if (debugMode) {
            ranGen = new Random(1);
        }
        else{
            ranGen = new Random();
        }
        prefSucc =new HashMap<Prefix, ArrayList<String>>();

    }

    public void sourceMap() {

        


    }

    public void initPref() {

        int initLoc = ranGen.nextInt(sourceLength + 1 - prefixLength);
        for (int i = 0; i < prefixLength; i++) {
            prefix.add(sourceWords.get(initLoc + i));
        }
        Prefix initPre = new Prefix(prefix);
    }
}
