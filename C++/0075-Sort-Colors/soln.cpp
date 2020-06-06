class Solution {
public:
    void sortColors(vector<int>& nums) {
        int lo = 0, hi = nums.size() - 1;
        int i = 0;
        while(i <= hi) {
            if (nums[i] == 0) {
                nums[lo] = 0;
                ++lo;
                ++i;
            } else if (nums[i] == 2) {
                swap(nums[i], nums[hi]);
                --hi;
            } else
                ++i;
        }
        while(lo <= hi) {
            nums[lo++] = 1;
        }
    }
};
