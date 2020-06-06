class Solution {
public:
    int minMoves(vector<int>& nums) {
        // decrease one
        int mn = *min_element(nums.begin(), nums.end());
        int ans = 0;
        for(int num : nums) {
            ans += num - mn;
        }
        return ans;
    }
};
