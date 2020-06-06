class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        const int kWordLen = word.length();
        const int kAbbrLen = abbr.length();
        int i = 0, j = 0;
        while (j < kAbbrLen) {
            int ch = abbr[j];
            if (isalpha(ch)) {
                if (i >= kWordLen || word[i] != ch) return false;
                ++i;
                ++j;
            } else {
                int num = 0;
                if (abbr[j] == '0' && j + 1 < kAbbrLen && isdigit(abbr[j + 1])) return false;
                while (j < kAbbrLen && isdigit(abbr[j])) {
                    num = num * 10 + (abbr[j++] - '0');
                }
                if (num == 0) return false;
                i += num;
            }
        }
        return i == kWordLen;
    }
};
