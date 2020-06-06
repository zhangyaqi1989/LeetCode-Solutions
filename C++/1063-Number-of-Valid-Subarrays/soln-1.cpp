class Solution {
public:
    int validSubarrays(vector<int>& nums) {
        stack<int> stk;
        int ans = 0;
        int n = nums.size();
        for(int i = 0; i < n; ++i) {
            while(!stk.empty() && nums[i] < nums[stk.top()]) {
                ans += i - stk.top();
                stk.pop();
            }
            stk.push(i);
        }
        while (!stk.empty()) {
            ans += n - stk.top();
            stk.pop();
        }
        return ans;
    }
};
