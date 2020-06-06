class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        map<int, int> memo;
        for(auto & update : updates) {
            memo[update[0]] += update[2];
            memo[update[1] + 1] -= update[2];
        }
        vector<int> ans(length);
        int acc = 0;
        int i = 0;
        for(auto & p : memo) {
            int idx = p.first;
            for(int k = i; k < idx; ++k) ans[k] = acc;
            i = idx;
            acc += p.second;
        }
        return ans;
        
    }
};
