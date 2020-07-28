class Solution {
public:
    int numKLenSubstrNoRepeats(string S, int K) {
        int window [26] = {0};
        int cnt = 0;
        int ans = 0;
        for(size_t i = 0; i < S.length(); ++i) {
            if(window[S[i] - 'a']++ == 0) ++cnt;
            if(i >= K) {
                if(window[S[i - K] - 'a']-- == 1) --cnt;
            }
            if(cnt >= K) ++ans;
        }
        return ans;
    }
};
