class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        vector<int> nums = {a, b, c};
        sort(nums.begin(), nums.end());
        int x = nums[0], y = nums[1], z = nums[2];
        int mx = z - x - 2;
        int mn;
        if (mx == 0) {
            mn = 0;
        } else if ((x + 1 == y || y + 1 == z) || (x + 2 == y || y + 2 == z)) {
            mn = 1;
        } else {
            mn = 2;
        }
        return {mn, mx};
    }
};
