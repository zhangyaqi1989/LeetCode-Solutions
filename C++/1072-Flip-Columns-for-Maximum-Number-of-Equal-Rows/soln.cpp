class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int> memo;
        for(vector<int> & row : matrix) {
            string h1 = "", h2 = "";
            int n = row.size();
            for(int j = 0; j < n; ++j) {
                if (row[j] == 1) {
                    h1 += "1";
                    h2 += "0";
                } else {
                    h1 += "0";
                    h2 += "1";
                }
            }
            memo[h1] += 1;
            memo[h2] += 1;
        }
        int ans = 0;
        for(auto & p : memo) {
            ans = max(ans, p.second);
        }
        return ans;
    }
};
