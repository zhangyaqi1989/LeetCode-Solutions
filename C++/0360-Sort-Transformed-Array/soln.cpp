class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        vector<int> ans;
        for(int num : nums) {
            ans.push_back(a * num * num + b * num + c);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
