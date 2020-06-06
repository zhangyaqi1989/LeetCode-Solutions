class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        // [qwertyuiop]*|[asdfghjkl]*|[zxcvbnm]*
        string rows[3] = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};
        int chars[26];
        for(int i = 0; i < 3; ++i) {
            string row = rows[i];
            for(char ch : row) chars[ch - 'a'] = i;
        }
        vector<string> ans;
        for(string word : words) {
            bool row_known = false;
            int row = 0;
            bool valid = true;
            for(char ch : word) {
                ch = tolower(ch);
                if (!row_known) {
                    row = chars[ch - 'a'];
                    row_known = true;
                } else {
                    if (chars[ch - 'a'] != row) {
                        valid = false;
                        break;
                    }
                }
            }
            if (valid) ans.push_back(word);
        }
        return ans;
        
    }
};
