class Solution {
public:
    vector<vector<int>> indexPairs(string text, vector<string>& words) {
        vector<vector<int>> ans;
        int n = text.length();
        for(string & word : words) {
            int m = word.length();
            for(int i = 0; i < n - m + 1; ++i) {
                if (text.substr(i, m) == word) ans.push_back({i, i + m - 1});
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
