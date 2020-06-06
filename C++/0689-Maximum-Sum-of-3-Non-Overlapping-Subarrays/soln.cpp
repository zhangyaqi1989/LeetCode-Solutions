class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int s1 = 0, s2 = 0, s3 = 0;
        for(int i = 0; i < k; ++i) s1 += nums[i];
        for(int i = k; i < 2 * k; ++i) s2 += nums[i];
        for(int i = 2 * k; i < 3 * k; ++i) s3 += nums[i];
        int besti1 = 0;
        vector<int> besti12 = {0, k};
        vector<int> besti123 = {0, k, 2 * k};
        int bests1 = s1, bests12 = s1 + s2, bests123 = s1 + s2 + s3;
        int idx1 = 0, idx2 = k, idx3 = 2 * k, n = nums.size();
        while (idx3 + k < n) {
            s1 += nums[idx1 + k] - nums[idx1];
            s2 += nums[idx2 + k] - nums[idx2];
            s3 += nums[idx3 + k] - nums[idx3];
            if (s1 > bests1) {
                bests1 = s1;
                besti1 = idx1 + 1;
            }
            if (bests1 + s2 > bests12) {
                bests12 = bests1 + s2;
                besti12 = {besti1, idx2 + 1};
            }
            if (bests12 + s3 > bests123) {
                bests123 = bests12 + s3;
                besti123 = {besti12[0], besti12[1], idx3 + 1};
            } 
            ++idx1;
            ++idx2;
            ++idx3;
        }
        return besti123;
    }
};
