class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int> & a, const vector<int> & b){
            return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
        });
        vector<vector<int>> merged;
        for(const auto & interval : intervals) {
            int s = interval[0], e = interval[1];
            if(merged.empty() || s > merged.back().back()) {
                merged.push_back({s, e});
            } else {
                merged.back().back() = max(merged.back().back(), e);
            }
        }
        return merged;
        
    }
};
