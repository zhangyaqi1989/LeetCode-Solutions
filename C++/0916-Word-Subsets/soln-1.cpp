class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        int chars[26] = {0};
        for(const auto & word : B) {
            int temp[26] = {0};
            for(char ch : word) {
                ++temp[ch - 'a'];
            }
            for(int i = 0; i < 26; ++i) {
                chars[i] = max(chars[i], temp[i]);
            }
        }
        vector<string> ans;
        for(const auto & word : A) {
            int temp[26] = {0};
            for(char ch : word) {
                ++temp[ch - 'a'];
            }
            bool valid = true;
            for(int i = 0; i < 26; ++i) {
                if (temp[i] < chars[i]) {
                    valid = false;
                    break;
                }
            }
            if (valid) ans.push_back(word);
        }
        return ans;
    }
};
