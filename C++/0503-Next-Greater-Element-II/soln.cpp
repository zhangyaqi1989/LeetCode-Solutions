class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> s;
        int m = 2 * n;
        for(int i = 0; i < m; ++i) {
            int j = i % n;
            int num = nums[j];
            while (!s.empty() && num > nums[s.top()]) {
                int idx = s.top();
                s.pop();
                ans[idx] = num;
            }
            s.push(j);
        }
        return ans;
    }
};
