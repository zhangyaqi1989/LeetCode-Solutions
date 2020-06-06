class Solution {
    public int isPrefixOfWord(String sentence, String p) {
        String [] words = sentence.split(" ");
        int np = p.length();
        for(int i = 1; i <= words.length; ++i) {
            String word = words[i - 1];
            if(word.length() >= p.length() && word.substring(0, np).equals(p)) {
                return i;
            }
        }
        return -1;
    }
}
