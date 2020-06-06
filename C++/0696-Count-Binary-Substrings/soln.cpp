class Solution {
public:
    int countBinarySubstrings(string s) {
        int cur = s[0], cnt = 0, ans = 0;
        s += '2';
        int pre = 0;
        for(char ch : s) {
            if (ch == cur) {
                ++cnt;
            } else {
                cur = ch;
                ans += min(pre, cnt);
                pre = cnt;
                cnt = 1;
            }
        }
        return ans;
    }
};
