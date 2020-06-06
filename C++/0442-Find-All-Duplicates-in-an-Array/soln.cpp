class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for(int i = 0; i < n; ++i) {
            int num = abs(nums[i]);
            if (nums[num - 1] < 0) 
                ans.push_back(num);
            nums[num - 1] *= -1;
        }
        return ans;
    }
};