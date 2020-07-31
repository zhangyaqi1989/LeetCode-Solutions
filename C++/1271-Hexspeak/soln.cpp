class Solution {
public:
    string toHexspeak(string num) {
        string str = "OIXXXXXXXXABCDEF";
        string ans;
        long long val = stoll(num);
        while(val) {
            char ch = str[val % 16];
            if(ch == 'X') return "ERROR";
            ans += ch;
            val /= 16;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
