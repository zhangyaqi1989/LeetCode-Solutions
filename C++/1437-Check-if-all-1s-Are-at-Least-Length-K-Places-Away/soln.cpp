class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int lo = -k - 1;
        int n = nums.size();
        for(int i = 0; i < n; ++i) {
            if(nums[i] == 1) {
                if(i - lo - 1 < k) return false;
                lo = i;
            }
        }
        return true;
    }
};
