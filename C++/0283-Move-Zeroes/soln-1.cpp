class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        const int kN = nums.size();
        int r_idx = 0;
        for(auto it = nums.begin(); it != nums.end(); ++it) {
            if (*it != 0) nums[r_idx++] = *it;
        }
        while(r_idx < kN) {
            nums[r_idx++] = 0;
        }
    }
};
