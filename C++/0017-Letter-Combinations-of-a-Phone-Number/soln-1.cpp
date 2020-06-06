class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<string> phone = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> level = {""};
        for(char ch : digits) {
            int idx = ch - '0';
            vector<string> nxt_level;
            for(string item : level) {
                for(char nxt : phone[idx]) {
                    nxt_level.push_back(item + nxt);
                }
            }
            swap(level, nxt_level);
        }
        return level;
    }
};
