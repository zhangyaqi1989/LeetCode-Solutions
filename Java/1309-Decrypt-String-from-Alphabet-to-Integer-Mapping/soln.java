class Solution {
    public String freqAlphabets(String s) {
        int n = s.length();
        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < n;) {
            if(i + 2 < n && s.charAt(i + 2) == '#') {
                char ch = (char)('j' + Integer.parseInt(s.substring(i, i + 2)) - 10);
                sb.append(ch);
                i += 3;
            } else {
                char ch = (char) (s.charAt(i) - '1' + 'a');
                sb.append(ch);
                ++i;
            }
        }
        return sb.toString();
    }
}
