class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        map<int, vector<int>> scores;
        for(vector<int> & p : items) {
            scores[p[0]].push_back(p[1]);
        }
        vector<vector<int>> ans;
        for(auto & p : scores) {
            sort(p.second.rbegin(), p.second.rend());
            ans.push_back({p.first, accumulate(p.second.begin(), p.second.begin() + 5, 0) / 5});
        }
        return ans;
    }
};
