class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        int B_chars[26] = {0};
        for(string & word : B) {
            int temp[26] = {0};
            for(char ch : word) {
                ++temp[ch - 'a'];
            }
            for(int i = 0; i < 26; ++i)
                B_chars[i] = max(B_chars[i], temp[i]);
        }
        vector<string> ans;
        for(string & str : A) {
            if (valid(str, B_chars)) ans.push_back(str);
        }
        return ans;
    }
    
    bool valid(string & str, int chars[]) {
        int temp[26] = {0};
        for(char ch : str) {
            ++temp[ch - 'a'];
        }
        for(int i = 0; i < 26; ++i) {
            if (chars[i] > temp[i]) return false;
        }
        // cout << "H";
        return true;
    }
};
