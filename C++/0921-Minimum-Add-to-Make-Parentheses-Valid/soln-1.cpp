class Solution {
public:
    int minAddToMakeValid(string S) {
        // ()))((
        // (((
        int cnt = 0;
        // ))) is more than
        int ans = 0;
        for(char ch : S) {
            if(ch == '(') {
                ++cnt;
            } else {
                if(cnt) --cnt;
                else {
                    ++ans;
                }
            }
        }
        return ans + cnt;
    }
};
