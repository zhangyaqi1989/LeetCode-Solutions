class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        # never do nums.size() - 1, since nums.size() is uint
        int n = nums.size();
        for(int i = 0; i < n - 1; ++i) {
            if (i % 2) {
                if(nums[i + 1] > nums[i])
                    swap(nums[i + 1], nums[i]);
            } else {
                if(nums[i + 1] < nums[i])
                    swap(nums[i + 1], nums[i]);
            }
        }
    }
};