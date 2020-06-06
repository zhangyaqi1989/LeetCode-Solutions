class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        vector<bool> visited(n, false);
        for(int i = 0; i < n; ++i) {
            if (!visited[i]) {
                int cnt = dfs(nums, visited, i);
                if (cnt > ans) ans = cnt;
            }
        }
        return ans;
    }
    
    int dfs(vector<int> & nums, vector<bool> & visited, int idx) {
        if (visited[idx]) return 0;
        visited[idx] = true;
        return 1 + dfs(nums, visited, nums[idx]);
    }
};
