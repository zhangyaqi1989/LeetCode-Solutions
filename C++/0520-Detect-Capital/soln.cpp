class Solution {
public:
    bool detectCapitalUse(string word) {
        int nupper = 0;
        for(char ch : word) {
            if (isupper(ch)) ++nupper;
        }
        if (nupper == 1 && isupper(word[0])) return true;
        return nupper == 0 || nupper == word.length();
    }
};
