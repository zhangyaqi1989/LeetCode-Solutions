auto desyncio = []()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        helper(ans, "", 0, 2 * n);
        return ans;
    }
    
    void helper(vector<string> & ans, string path, int cnt, int n) {
        if (cnt < 0) return;
        if (path.length() == n) {
            if (cnt == 0) ans.push_back(path);
        } else {
            helper(ans, path + '(', cnt + 1, n);
            helper(ans, path + ')', cnt - 1, n);
        }
    }
};
