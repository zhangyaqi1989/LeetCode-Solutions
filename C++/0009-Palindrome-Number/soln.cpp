class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        string s = to_string(x);
        string rs(s);
        reverse(rs.begin(), rs.end());
        return s == rs;
    }
};
