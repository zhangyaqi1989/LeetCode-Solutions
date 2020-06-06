class Solution {
    public int titleToNumber(String s) {
        int ans = 0;
        for(char ch : s.toCharArray()) {
            ans = ans * 26 + (ch - 'A' + 1);
        }
        return ans;
    }
}
