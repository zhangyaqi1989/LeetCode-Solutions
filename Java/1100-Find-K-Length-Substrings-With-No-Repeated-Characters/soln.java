class Solution {
    public int numKLenSubstrNoRepeats(String S, int K) {
        int [] window = new int [26];
        int cnt = 0, ans = 0;
        for(int i = 0; i < S.length(); ++i) {
            if(window[S.charAt(i) - 'a']++ == 0) ++cnt;
            if(i >= K) {
                if(window[S.charAt(i - K) - 'a']-- == 1) --cnt;
            }
            if(cnt == K) ++ans;
        }
        return ans;
    }
}
