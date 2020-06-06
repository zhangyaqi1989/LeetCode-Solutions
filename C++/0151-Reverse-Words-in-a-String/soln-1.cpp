class Solution {
public:
    string reverseWords(string s) {
        vector<string> tokens;
        istringstream iss(s);
        string token;
        while (iss >> token) {
            tokens.push_back(token);
        }
        reverse(tokens.begin(), tokens.end());
        string ans = "";
        for(int i = 0; i < tokens.size(); ++i) {
            if (ans.length() > 0) ans += " ";
            ans += tokens[i];
        }
        return ans;
    }
};
