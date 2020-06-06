class Solution {
public:
    bool xorGame(vector<int>& nums) {
        int ans = 0;
        for(int num : nums) ans ^= num;
        return ans == 0 || nums.size() % 2 == 0;
    }
};
