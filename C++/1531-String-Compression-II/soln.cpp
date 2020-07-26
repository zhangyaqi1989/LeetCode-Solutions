int memo[105][105][27][105];

class Solution {
public:
    int getLengthOfOptimalCompression(string s, int k) {
        memset(memo, -1, sizeof memo);
        return Helper(s, 0, k, 26, 0);
    }
    
    int Helper(const string & s, int start, int left, int last, int cnt) {
        if(left < 0) return s.length() * 10;
        if(start >= s.length()) return 0;
        if(last < 26 && memo[start][left][last][cnt] != -1) return memo[start][left][last][cnt];
        int ans = s.length() * 10;
        if(s[start] - 'a' == last) {
            int inc = (cnt == 1 || cnt == 9 || cnt == 99) ? 1 : 0;
            ans = inc + Helper(s, start + 1, left, last, cnt + 1);
        } else {
            ans = min(ans, min(1 + Helper(s, start + 1, left, s[start] - 'a', 1), Helper(s, start + 1, left - 1, last, cnt)));
        }
        return memo[start][left][last][cnt] = ans;
    }
};
