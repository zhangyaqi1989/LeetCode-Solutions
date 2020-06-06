class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int diff = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
        int mask = 1;
        while ((diff & mask) == 0)
            mask <<= 1;
        int a = 0, b = 0;
        for(auto num : nums)
        {
            if (num & mask) a ^= num;
            else b ^= num;
        }
        return {a, b};
    }
};