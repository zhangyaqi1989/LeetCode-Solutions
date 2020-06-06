class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        int plates[26] = {0};
        for(char ch : licensePlate) {
            if (isalpha(ch)) {
                ++plates[tolower(ch) - 'a'];
            }
        }
        string ans = "";
        int mn = INT_MAX;
        for(string & word : words) {
            int m[26] = {0};
            for(char ch : word) {
                if (isalpha(ch)) {
                    ++m[tolower(ch) - 'a'];
                }
            }
            bool valid = true;
            for(int i = 0; i < 26; ++i) {
                if (m[i] < plates[i]) {
                    valid = false;
                    break;
                }
            }
            if (valid && word.length() < mn) {
                ans = word;
                mn = word.length();
            }
        }
        return ans;
    }
};
