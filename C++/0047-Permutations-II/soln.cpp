class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        ans.push_back({});
        sort(nums.begin(), nums.end());
        for(int num : nums) {
            // cout << num << endl;
            vector<vector<int>> temp;
            for(auto lst : ans) {
                for(int i = 0; i <= lst.size(); ++i) {
                    if (i > 0 && lst[i - 1] == num) break;
                    vector<int> clst(lst);
                    clst.insert(clst.begin() + i, num);
                    temp.push_back(clst);
                }
            }
            swap(temp, ans);
        }
        return ans;
    }
};
