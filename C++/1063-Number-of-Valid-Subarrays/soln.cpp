class Solution {
public:
    int validSubarrays(vector<int>& nums) {
        int cnt = 0, n = nums.size();
        stack<int> stk;
        for(int i = 0; i < n; ++i) {
            while (!stk.empty() && nums[i] < nums[stk.top()]) {
                cnt += i - stk.top();
                stk.pop();
            }
            stk.push(i);
        }
        while(!stk.empty()) {
            cnt += n - stk.top();
            stk.pop();
        }
        return cnt;
    }
};
