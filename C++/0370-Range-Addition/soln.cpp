class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        // linear
        vector<int> records(length + 1, 0);
        for(auto & update : updates) {
            records[update[0]] += update[2];
            records[update[1] + 1] -= update[2];
        }
        int acc = 0;
        vector<int> ans(length, 0);
        for(int i = 0; i < length; ++i) {
            acc += records[i];
            ans[i] = acc;
        }
        return ans;
        
    }
};