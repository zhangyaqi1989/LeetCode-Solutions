class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int i = 0, n = word.length();
        int num = 0;
        for(char ch : abbr) {
            if(isdigit(ch)) {
                if (num == 0 && ch == '0') return false;
                num = num * 10 + (ch - '0');
            } else {
                if (num != 0) i += num;
                num = 0;
                if (i >= n || ch != word[i]) return false;
                ++i;
            }
        }
        i += num;
        return i == n;
    }
};
