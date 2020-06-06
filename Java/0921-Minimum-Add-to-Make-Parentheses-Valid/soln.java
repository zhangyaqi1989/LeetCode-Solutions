class Solution {
    public int minAddToMakeValid(String S) {
        int ans = 0, cnt = 0;
        for(int ch : S.toCharArray()) {
            if (ch == '(') {
                ++cnt;
            } else {
                if (--cnt < 0) {
                    cnt = 0;
                    ++ans;
                }
            }
        }
        return ans + cnt;
    }
}
