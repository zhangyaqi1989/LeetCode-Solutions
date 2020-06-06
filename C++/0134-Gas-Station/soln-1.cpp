typedef long long ll;
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        ll sg = 0LL, sc = 0LL;
        for(int num : gas) sg += num;
        for(int num : cost) sc += num;
        if (sg < sc) return -1;
        int start = 0;
        ll tank = 0;
        int n = gas.size();
        for(int i = 0; i < n; ++i) {
            tank += gas[i];
            if (tank >= cost[i]) {
                tank -= cost[i];
            } else {
                tank = 0;
                start = (i + 1) % n;
            }
        }
        return start;
    }
};
