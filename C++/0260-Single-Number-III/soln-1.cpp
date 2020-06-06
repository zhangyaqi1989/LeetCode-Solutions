class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int diff = 0;
        for(int num : nums) diff ^= num;
        diff &= -diff;
        int a = 0, b = 0;
        for(int num : nums) {
            if (num & diff) a ^= num;
            else b ^= num;
        }
        return {a, b};
    }
};
