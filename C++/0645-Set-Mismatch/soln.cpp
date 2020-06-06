class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        // 1 to n
        int rep = 0, mis = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[abs(nums[i]) - 1] < 0)
                rep = abs(nums[i]);
            else
                nums[abs(nums[i]) - 1] *= -1;
        }
        // mis
        for (int i = 0; i < nums.size(); ++i)
            if(nums[i] > 0)
                mis = i + 1;
        return {rep, mis};
    }
};