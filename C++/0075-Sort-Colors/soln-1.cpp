class Solution {
public:
    void sortColors(vector<int>& nums) {
        const int kN = nums.size();
        int lo = 0, hi = kN - 1;
        for(int i = lo; i <= hi; ++i) {
            if (nums[i] == 0) {
                swap(nums[i], nums[lo++]);
            } else if (nums[i] == 2) {
                swap(nums[i], nums[hi--]);
                --i;
            }
        }
    }
};
