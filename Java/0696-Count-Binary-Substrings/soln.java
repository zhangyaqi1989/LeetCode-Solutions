class Solution {
    public int countBinarySubstrings(String s) {
        int cur = s.charAt(0), cnt = 0, ans = 0;
        int pre = 0;
        s += '2';
        // System.out.println(s);
        for(char ch : s.toCharArray()) {
            if (ch == cur) {
                ++cnt;
            } else {
                cur = ch;
                ans += Math.min(pre, cnt);
                pre = cnt;
                cnt = 1;
            }
        }
        return ans;
    }
}
