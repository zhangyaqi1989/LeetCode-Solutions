class Solution {
    public char findTheDifference(String s, String t) {
        int[] chars = new int[26];
        for(char ch : s.toCharArray()) ++chars[ch - 'a'];
        for(char ch : t.toCharArray()) {
            if (chars[ch - 'a']-- == 0) return ch;
        }
        return ' ';
    }
}
