class Solution {
public:
    string thousandSeparator(int n) {
        if(n == 0) return "0";
        string ans;
        int idx = 0;
        while(n) {
            ans += '0' + (n % 10);
            if(++idx % 3 == 0 && n > 9) ans += '.';
            n /= 10;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
