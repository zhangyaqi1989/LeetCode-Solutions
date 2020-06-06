class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int min_num = nums[0];
        int max_num = nums[0];
        int res = nums[0];
        for(int i = 1; i < nums.size(); ++i)
        {
            int temp = min_num;
            min_num = min(nums[i], min(min_num * nums[i], max_num * nums[i]));
            max_num = max(nums[i], max(temp * nums[i], max_num * nums[i]));
            res = max(res, max_num);
        }
        return res;
    }
};