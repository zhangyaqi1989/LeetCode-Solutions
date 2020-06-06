class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> tokens, ans;
        istringstream iss(text);
        string token;
        while (iss >> token) tokens.push_back(token);
        int n = tokens.size();
        for(int i = 0; i < n - 2; ++i) {
            if (tokens[i] == first && tokens[i + 1] == second) ans.push_back(tokens[i + 2]);
        }
        return ans;
    }
};
