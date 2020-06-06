class Solution {
public:
    string toLowerCase(string str) {
        string ans = "";
        for(char ch : str) {
            if (ch >= 'A' && ch <= 'Z') {
                ans += ch - ('A' - 'a');
            } else {
                ans += ch;
            }
        }
        return ans;
    }
};
