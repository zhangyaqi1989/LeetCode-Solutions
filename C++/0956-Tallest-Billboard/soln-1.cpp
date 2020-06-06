class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        // a, b
        const int n = rods.size();
        if (n < 2) return 0;
        unordered_map<int, int> dp;
        dp[0] = 0;
        for(int i = 0; i < n; ++i) {
            unordered_map<int, int> nxt;
            for(auto & p : dp) {
                int diff, sum;
                diff = p.first;
                sum = p.second;
                auto it = nxt.find(diff + rods[i]);
                if (it != nxt.end()) {
                    nxt[diff + rods[i]] = max(sum + rods[i], it->second);
                } else nxt[diff + rods[i]] = sum + rods[i];
                it = dp.find(diff + rods[i]);
                if (it != dp.end()) nxt[diff + rods[i]] = max(nxt[diff + rods[i]], it->second);
                it = nxt.find(abs(diff - rods[i]));
                if(it != nxt.end()) {
                    nxt[abs(diff - rods[i])] = max(nxt[abs(diff - rods[i])], sum + rods[i]);
                } else nxt[abs(diff - rods[i])] = sum + rods[i];
                it = dp.find(abs(diff - rods[i]));
                if (it != dp.end()) nxt[abs(diff - rods[i])] = max(nxt[abs(diff - rods[i])], it->second);
            }
            for(auto & p : dp) {
                nxt[p.first] = max(nxt[p.first], p.second);
            }
            nxt[rods[i]] = max(nxt[rods[i]], rods[i]);
            swap(dp, nxt);
        }
        int mx = 0;
        for(auto & p : dp) {
            // cout << p.first << " " << p.second << endl;
            if(p.first == 0) mx = max(mx, p.second / 2);
        }
        return mx;
    }
};
