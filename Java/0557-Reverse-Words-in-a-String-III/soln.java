class Solution {
    public String reverseWords(String s) {
        String[] tokens = s.split(" ");
        StringBuilder sb = new StringBuilder();
        for(String token : tokens) {
            sb.append(reverseWord(token));
            sb.append(" ");
        }
        sb.setLength(sb.length() - 1);
        return sb.toString();
    }

    public String reverseWord(String word) {
        StringBuilder sb = new StringBuilder(word);
        return sb.reverse().toString();
    }
}
