class Solution {
    public int maxScore(String s) {
        int n = s.length();
        int ones = 0;
        int zeros = 0;
        for(char ch : s.toCharArray()) {
            if(ch == '1') ++ones;
        }
        int ans = -1;
        for(int i = 0; i < n - 1; ++i) {
            if(s.charAt(i) == '0') ++zeros;
            if(s.charAt(i) == '1') --ones;
            ans = Math.max(ans, zeros + ones);
        }
        return ans;
    }
}
