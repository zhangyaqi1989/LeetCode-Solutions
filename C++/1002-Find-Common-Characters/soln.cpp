class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<int> chars(26, INT_MAX);
        for (string & str : A) {
            int temp[26] = {0};
            for(char ch : str) {
                ++temp[ch - 'a'];
            }
            for(int i = 0; i < 26; ++i) chars[i] = min(chars[i], temp[i]);
        }
        vector<string> ans;
        for(int i = 0; i < 26; ++i) {
            for(int j = 0; j < chars[i]; ++j) {
                ans.push_back(string(1, 'a' + i));
            }
        }
        return ans;
    }
};
