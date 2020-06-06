class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        // keep a window
        int product = 1;
        int lo = 0, cnt = 0;
        const int kN = nums.size();
        for(int i = 0; i < kN; ++i) {
            product *= nums[i];
            while (lo <= i && product >= k) {
                product /= nums[lo++];
            }
            cnt += i - lo + 1;
        }
        return cnt;
    }
};
