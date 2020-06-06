class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> res;
        helper(S, 0, "", res);
        return res;
    }
    
    void helper(string S, int idx, string path, vector<string>& res)
    {
        if(idx == S.size())
        {
            res.push_back(path);
            return;
        }
        helper(S, idx + 1, path + string(1, S[idx]), res);
        if (S[idx] >= 'a' && S[idx] <= 'z')
            helper(S, idx + 1, path + string(1, S[idx] - 32), res);
        if (S[idx] >= 'A' && S[idx] <= 'Z')
            helper(S, idx + 1, path + string(1, S[idx] + 32), res);
    }
};