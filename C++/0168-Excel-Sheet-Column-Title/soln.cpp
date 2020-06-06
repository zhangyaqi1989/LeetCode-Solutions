class Solution {
public:
    string convertToTitle(int n) {
        string s = "";
        while (n != 0) {
            --n;
            int val = n % 26;
            n /= 26;
            s += ('A' + val);
        }
        reverse(s.begin(), s.end());
        return s;
    }
};
