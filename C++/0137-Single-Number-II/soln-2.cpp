class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> digits(32, 0);
        for(int num : nums) {
            // extract each digit
            for(int i = 0; i < 32; ++i) {
                if (num & (1 << i)) ++digits[i];
            }
        }
        int ans = 0;
        for(int i = 0; i < 32; ++i) {
            if (digits[i] % 3) ans += (1 << i);
        }
        return ans;
    }
};
