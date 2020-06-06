class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int> chars;
        for(char ch : s) ++chars[ch];
        int odds = 0;
        for(auto & p : chars) odds += p.second % 2;
        return odds > 0 ? s.length() - odds + 1 : s.length();
    }
};
