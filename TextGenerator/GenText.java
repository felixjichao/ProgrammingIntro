import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.*;
import java.util.concurrent.Semaphore;

public class GenText {
    public static void main(String[] args) {
        String fileName = "";

        try {

            if (args.length < 4) {
                System.out.println("ERROR: missing some command line argument");
            }
            else {
                if (args[0].equals("-d")) {
                    fileName = args[3];
                }
                else {
                    fileName = args[2];
                }

                Set<Prefix> test = new HashSet<Prefix>();
                ArrayList<String> t1 = new ArrayList<String>();
                t1.add("a");
                Prefix test1 = new Prefix(t1);
                test.add(test1);
                ArrayList<String> t2 = new ArrayList<String>();
                t2.add("a");
                Prefix test2 = new Prefix(t2);
                test.add(test2);

                readFile(fileName);

//                Prefix sourceFile = new Prefix(Integer.parseInt(args[args.length - 4]),
//                        readFile(fileName));

                //String[] init = sourceFile.initPrefix();
            }

        }
        catch (FileNotFoundException exc) {
            System.out.println("File not found: " + fileName);
        }

    }

    public static void arguCheck(String[] args) {
        String outFileName = args[args.length - 1];
        String sourceFileNmae = args[args.length - 2];
        int numWords = Integer.parseInt(args[args.length - 3]);

    }

    public static Map<Integer,String> readFile(String fileName)
                                                throws FileNotFoundException {
        File inputFile = new File(fileName);
        Scanner in = new Scanner(inputFile);
        Map<Integer,String> sourceWords = new HashMap<Integer, String>();
        int totalNum = 1;

        while (in.hasNext()) {
            sourceWords.put(totalNum, in.next());
            totalNum++;
        }


        return sourceWords;
    }
}