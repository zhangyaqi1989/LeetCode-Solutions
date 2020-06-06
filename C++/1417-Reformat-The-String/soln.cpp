class Solution {
public:
    string reformat(string s) {
        string s1, s2;
        for(char ch : s) {
            if(isdigit(ch)) s1 += ch;
            else s2 += ch;
        }
        if(s1.length() < s2.length()) swap(s1, s2);
        if((int) s1.length() - 1 > s2.length()) return "";
        string ans;
        for(int i = 0; i < s2.length(); ++i) {
            ans += s1[i];
            ans += s2[i];
        }
        if (s1.length() > s2.length()) ans += s1.back();
        return ans;
    }
};
