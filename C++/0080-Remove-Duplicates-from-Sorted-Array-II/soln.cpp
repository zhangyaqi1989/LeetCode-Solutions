class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0; // write
        int j = 0, cnt = 0;
        if (nums.size())
            nums.push_back(nums[nums.size() - 1] + 1);
        for(int k = 0; k < nums.size(); ++k) {
            if(nums[k] != nums[j]) {
                for(int p = 0; p < min(2, cnt); ++p)
                    nums[i++] = nums[j];
                j = k;
                cnt = 1;
            } else {
                ++cnt;
            }
        }
        return i;
    }
};