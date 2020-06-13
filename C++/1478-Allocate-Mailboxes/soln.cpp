const int kN = 105;
int memo[kN][kN];

class Solution {
public:
    int minDistance(vector<int>& houses, int k) {
        memset(memo, -1, sizeof memo);
        sort(houses.begin(), houses.end());
        return Helper(houses, 0, k);
    }
    
    int Helper(const vector<int> & houses, int idx, int k) {
        int n = houses.size();
        if(n - idx <= k) return 0;
        if(k < 0) return -1;
        if(memo[idx][k] != -1) return memo[idx][k];
        int ans = -1;
        int lo = idx;
        for(int nxt = idx + 1; nxt <= n; ++nxt) {
            int hi = nxt - 1;
            int place = houses[lo + (hi - lo) / 2];
            int cost = 0;
            for(int i = lo; i <= hi; ++i) cost += abs(place - houses[i]);
            int tail = Helper(houses, nxt, k - 1);
            if (tail != -1) {
                if (ans == -1) ans = tail + cost;
                else ans = min(ans, tail + cost);
            }
        }
        return memo[idx][k] = ans;
    }
};
