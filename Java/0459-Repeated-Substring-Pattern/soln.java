class Solution {
    public boolean repeatedSubstringPattern(String s) {
        String ss = (s + s).substring(1, 2 * s.length() - 1);
        return ss.indexOf(s) != -1;
    }
}
