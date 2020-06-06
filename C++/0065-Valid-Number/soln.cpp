class Solution {
public:
    bool isNumber(string s) {
        const int n = s.length();
        int i = 0;
        while(i < n && s[i] == ' ') ++i;
        if(i < n && (s[i] == '+' || s[i] == '-')) ++i;
        int n_num = 0, n_pt = 0;
        while(i < n && ((s[i] >= '0' && s[i] <= '9') || s[i] == '.')) {
            if (s[i] == '.') ++n_pt;
            else ++n_num;
            ++i;
        }
        if (n_pt > 1 || n_num < 1) return false;
        if (i < n && s[i] == 'e') {
            ++i;
            if(i < n && (s[i] == '+' || s[i] == '-')) ++i;
            n_num = 0;
            while(i < n && (s[i] >= '0' && s[i] <= '9')) {
                ++n_num;
                ++i;
            }
            if (n_num < 1) return false;
        }
        while(i < n && s[i] == ' ') ++i;
        return i == n;
    }
};
