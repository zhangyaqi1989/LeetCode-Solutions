class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        unordered_map<int, int> dp;
        dp[0] = 0;
        for(int rod : rods) {
            unordered_map<int, int> temp;
            for(auto & p : dp) {
                temp[p.first + rod] = max(temp[p.first + rod], p.second + rod);
                temp[p.first] = max(temp[p.first], p.second);
                temp[p.first - rod] = max(temp[p.first - rod], p.second);
            }
            swap(temp, dp);
        }
        return dp[0];
    }
};
