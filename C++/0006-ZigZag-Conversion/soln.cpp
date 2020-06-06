auto desyncio = []()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

// ALG: simulation

class Solution {
public:
    string convert(string s, int numRows) {
        if(s.length() <= numRows || numRows == 1) return s;
        vector<string> ans(numRows, "");
        int n = s.length();
        int row = 0, drow = 1;
        for(auto ch : s) {
            ans[row] += ch;
            row += drow;
            if (row == numRows - 1 || row == 0) drow = -drow;
        }
        return accumulate(ans.begin(), ans.end(), string(""));
    }
};
