class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int mn = INT_MAX;
        int cur = 0;
        for(int num : nums) {
            cur += num;
            mn = min(cur, mn);
        }
        return max(1, 1 - mn);
    }
};
