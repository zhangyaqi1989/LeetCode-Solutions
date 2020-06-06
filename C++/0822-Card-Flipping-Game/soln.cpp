class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        set<int> bads;
        int n = fronts.size();
        int ans = INT_MAX;
        for(int i = 0; i < n; ++i) {
            if (fronts[i] == backs[i]) bads.insert(fronts[i]);
        }
        for(int i = 0; i < n; ++i) {
            if (bads.find(fronts[i]) == bads.end()) {
                int a = fronts[i];
                if (a < ans) ans = a;
            }
            if (bads.find(backs[i]) == bads.end()) {
                int b = backs[i];
                if (b < ans) ans = b;
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};
