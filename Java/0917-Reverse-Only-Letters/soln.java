class Solution {
    public String reverseOnlyLetters(String S) {
        char [] chars = S.toCharArray();
        int lo = 0, hi = chars.length - 1;
        while(lo < hi) {
            while(lo < hi && !Character.isLetter(chars[lo])) ++lo;
            while(lo < hi && !Character.isLetter(chars[hi])) --hi;
            char temp = chars[lo];
            chars[lo] = chars[hi];
            chars[hi] = temp;
            ++lo;
            --hi;
        }
        return String.valueOf(chars);
    }
}
