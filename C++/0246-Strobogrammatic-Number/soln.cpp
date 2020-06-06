class Solution {
public:
    bool isStrobogrammatic(string num) {
        string bads = "23457";
        for(char ch : num) {
            if (bads.find(ch) != string::npos) return false;
        }
        int lo = 0, hi = num.length() - 1;
        while (lo <= hi) {
            char ch = num[lo];
            char new_ch = ch;
            if (ch == '6') new_ch = '9';
            else if (ch == '9') new_ch = '6';
            if (new_ch != num[hi]) return false;
            ++lo;
            --hi;
        }
        return true;
    }
};
