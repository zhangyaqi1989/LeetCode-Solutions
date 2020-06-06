class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";
        while (n > 1) {
            ans = say(ans);
            --n;
        }
        return ans;
    }
    
    string say(string str) {
        string ans = "";
        str += '#';
        int cnt = 0;
        char cur_ch = str[0];
        for (char ch : str) {
            if (cur_ch == ch) {
                cnt += 1;
            } else {
                ans += to_string(cnt);
                ans += cur_ch;
                cur_ch = ch;
                cnt = 1;
            }
        }
        return ans;
    }
};
