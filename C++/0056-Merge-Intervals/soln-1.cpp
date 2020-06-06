class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), 
             [&](vector<int> & a, vector<int> & b) {
                 return a[0] < b[0];
             });
        vector<vector<int>> merged;
        for(auto & inter : intervals) {
            if (merged.empty() || inter[0] > merged.back()[1]) {
                merged.push_back(inter);
            } else {
                merged.back()[1] = max(merged.back()[1], inter[1]);
            }
        }
        return merged;
            
    }
};
