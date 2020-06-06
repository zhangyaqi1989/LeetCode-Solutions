class Solution {
    public String reverseVowels(String s) {
        String vowels = "aeiouAEIOU";
        int lo = 0, hi = s.length() - 1;
        char [] chars = s.toCharArray();
        while(lo < hi) {
            while(lo < hi && vowels.indexOf(chars[lo]) == -1) {
                ++lo;
            }
            while(lo < hi && vowels.indexOf(chars[hi]) == -1) {
                --hi;
            }
            if (lo < hi) {
                char temp = chars[lo];
                chars[lo] = chars[hi];
                chars[hi] = temp;         
            }
            ++lo;
            --hi;
        }
        return String.valueOf(chars);
    }
}
