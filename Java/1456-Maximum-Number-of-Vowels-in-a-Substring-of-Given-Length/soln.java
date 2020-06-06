class Solution {
    public int maxVowels(String s, int k) {
        String vowels = "AEIOUaeiou";
        int mx = 0;
        int n = s.length();
        int window = 0;
        for(int i = 0; i < n; ++i) {
            if(vowels.indexOf(s.charAt(i)) != -1) ++window;
            if(i >= k && vowels.indexOf(s.charAt(i - k)) != -1) --window;
            if(i >= k - 1) mx = Math.max(mx, window);
        }
        return mx;
    }
}
