class Solution {
    public int lengthOfLastWord(String s) {
        int n = s.length();
        --n;
        while(n >= 0 && Character.isSpace(s.charAt(n))) {
            --n;
        }
        int i = n;
        while(i >= 0 && !Character.isSpace(s.charAt(i))) {
            --i;
        }
        return n - i;
    }
}
