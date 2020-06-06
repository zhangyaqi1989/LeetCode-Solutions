class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans = {{}};
        for(int num : nums) {
            vector<vector<int>> temp;
            for(auto lst : ans) {
                for(int i = 0; i <= lst.size(); ++i) {
                    vector<int> x(lst);
                    x.insert(x.begin() + i, num);
                    temp.push_back(x);
                }
            }
            swap(temp, ans);
        }
        return ans;
    }
};
