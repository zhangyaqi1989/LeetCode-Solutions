class Solution {
    public int calculateTime(String keyboard, String word) {
        int [] positions = new int [26];
        for(int i = 0; i < 26; ++i) {
            positions[keyboard.charAt(i) - 'a'] = i;
        }
        int ans = 0;
        for(int i = 0; i < word.length(); ++i) {
            if(i == 0) ans += positions[word.charAt(i) - 'a'];
            else {
                ans += Math.abs(positions[word.charAt(i) - 'a'] - positions[word.charAt(i - 1) - 'a']);
            }
        }
        return ans;
    }
}
