class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int gas_total = accumulate(gas.begin(), gas.end(), 0);
        int cost_total = accumulate(cost.begin(), cost.end(), 0);
        if (cost_total > gas_total) return -1;
        int cur = 0, n = gas.size();
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            cur += gas[i] - cost[i];
            if (cur < 0) {
                cur = 0;
                ans = i + 1;
            }
        }
        return ans;
    }
};
