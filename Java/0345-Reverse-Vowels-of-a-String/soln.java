class Solution {
    public String reverseVowels(String s) {
        String vowels = "AEIOUaeiou";
        char[] chars = s.toCharArray();
        int lo = 0, n = s.length(), hi = n - 1;
        while (lo < hi) {
            while (lo < hi && vowels.indexOf(chars[lo]) == -1) ++lo;
            while (lo < hi && vowels.indexOf(chars[hi]) == -1) --hi;
            if (lo < hi) {
                char temp = chars[lo];
                chars[lo] = chars[hi];
                chars[hi] = temp;
            }
            ++lo;
            --hi;
        }
        return String.copyValueOf(chars);
    }
}
