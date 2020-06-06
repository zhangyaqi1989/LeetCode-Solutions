class Solution {
public:
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
        vector<vector<int>> ans;
        int rs = toBeRemoved[0], re = toBeRemoved[1];
        for(const auto & interval : intervals) {
            int s = interval[0], e = interval[1];
            if (rs >= e || s >= re) {
                ans.push_back({s, e});
            } else {
                if (rs > s) {
                    ans.push_back({s, rs});
                }
                if (e > re) {
                    ans.push_back({re, e});
                } 
            }
        }
        return ans;
    }
};
