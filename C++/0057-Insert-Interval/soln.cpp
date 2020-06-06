class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int news = newInterval[0], newe = newInterval[1];
        bool insert = false;
        for(const auto & inter : intervals) {
            if (inter[1] < news) {
                ans.push_back({inter[0], inter[1]});
            } else if (inter[0] > newe) {
                if (!insert) {
                    insert = true;
                    ans.push_back({news, newe});
                }
                ans.push_back({inter[0], inter[1]});
            } else {
                news = min(news, inter[0]);
                newe = max(newe, inter[1]);
            }
        }
        if (!insert) ans.push_back({news, newe});
        return ans;
    }
};
