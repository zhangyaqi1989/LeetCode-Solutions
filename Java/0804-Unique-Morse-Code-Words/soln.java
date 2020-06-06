class Solution {
    public int uniqueMorseRepresentations(String[] words) {
        String [] d = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
        Set<String> codes = new HashSet<>();
        for(String word : words) {
            StringBuilder sb = new StringBuilder();
            for(char ch : word.toCharArray()) {
                sb.append(d[ch - 'a']);
            }
            codes.add(sb.toString());
        }
        return codes.size();
    }
}
