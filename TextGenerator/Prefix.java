import java.util.ArrayList;


public class Prefix {
    private ArrayList<String> prefix;

    public Prefix(ArrayList<String> prefix) {
        this.prefix = prefix;
    }

    public Prefix nextPrefix(String nextWord) {
        prefix.remove(0);
        prefix.add(nextWord);
        return new Prefix(prefix);
    }

    public Prefix currPrefix() {
        return new Prefix(prefix);
    }

    public String getWordAt(int loc) {
        if (loc >= 0 && loc < prefix.size()) {
            return prefix.get(loc);
        }
        return null;
    }

    public String toString() {
        String strPrefix= new String();
        for (int i = 0; i < prefix.size() - 1; i++) {
            strPrefix = strPrefix + " " + prefix.get(i);
        }
        strPrefix += prefix.get(prefix.size() - 1);
        return "prefix: " + strPrefix;
    }

    public boolean equals(Object anObject) {
        Prefix comPrefix = (Prefix)anObject;
        for (int i = 0; i < prefix.size(); i++) {
            if (!prefix.get(i).equals(comPrefix.getWordAt(i))) {
                return false;
            }
        }
        return true;
    }

    public int hashCode() {
        int hashCode = 0;
        for (int i = 0; i < prefix.size(); i++) {
            hashCode += prefix.get(i).hashCode();
        }
        return hashCode;
    }

}