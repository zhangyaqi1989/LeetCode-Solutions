class Solution {
    public int maxNumberOfBalloons(String text) {
        int [] chars = new int [26];
        for(char ch : text.toCharArray()) {
            ++chars[ch - 'a'];
        }
        int [] cnts ={chars['a' - 'a'], chars['b' - 'a'], chars['l' - 'a'] / 2, chars['o' - 'a'] / 2, chars['n' - 'a']};
        int ans = text.length();
        for(int cnt : cnts) ans = Math.min(ans, cnt);
        return ans;
    }
}
