class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        // (h, k)
        // longer one comes first and insert
        sort(people.begin(), people.end(), [](const vector<int> & a, const vector<int> & b) {
            return a[0] == b[0] ? a[1] < b[1] : a[0] > b[0];
        });
        vector<vector<int>> ans;
        for(auto p : people) {
            int idx = p[1];
            ans.insert(ans.begin() + idx, p);
        }
        return ans;
    }
};
