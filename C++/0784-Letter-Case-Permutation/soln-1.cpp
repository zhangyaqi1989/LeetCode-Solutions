class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> ans;
        dfs(S, 0, ans, "");
        return ans;
    }
    
    void dfs(string S, int idx, vector<string> & ans, string path) {
        if (idx == S.length()) {
            ans.push_back(path);
        } else {
            if ('0' <= S[idx] && S[idx] <= '9') dfs(S, idx + 1, ans, path + S[idx]);
            else {
                dfs(S, idx + 1, ans, path + string(1, tolower(S[idx])));
                dfs(S, idx + 1, ans, path + string(1, toupper(S[idx])));
            }
        }
    }
};
