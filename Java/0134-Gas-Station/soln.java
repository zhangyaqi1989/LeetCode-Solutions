class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        int total_gas = 0, total_cost = 0, n = gas.length;
        for(int i = 0; i < n; ++i) {
            total_gas += gas[i];
            total_cost += cost[i];
        }
        if (total_cost > total_gas) return -1;
        int ans = 0, cur = 0;
        for(int i = 0; i < n; ++i) {
            cur += gas[i] - cost[i];
            if (cur < 0) {
                cur = 0;
                ans = i + 1;
            }
        }
        return ans;
    }
}
