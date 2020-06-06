class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int ans = 0;
        vector<int> bits(31, 0);
        for(int num : nums) {
            for(int i = 0; i < 31; ++i) {
                if (num & (1 << i)) ++bits[i];
            }
        }
        const int kN = nums.size();
        for(int i = 0; i < 31; ++i) {
            ans += bits[i] * (kN - bits[i]);
        }
        return ans;
    }
};
