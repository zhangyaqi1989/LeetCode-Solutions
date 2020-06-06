class Solution {
public:
    string toGoatLatin(string S) {
        istringstream iss(S);
        string ans = "";
        int i = 0;
        string token;
        string vowels = "aeiouAEIOU";
        while (getline(iss, token, ' ')) {
            ++i;
            char first = token[0];
            if (ans.length() != 0) ans += " ";
            if (vowels.find(first) != string::npos) {
                ans += token + "ma" + string(i, 'a');
            } else {
                ans += token.substr(1) + token[0] + "ma" + string(i, 'a');
            }
        }
        return ans;
    }
};
