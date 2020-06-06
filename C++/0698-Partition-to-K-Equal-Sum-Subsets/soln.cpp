class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        if (n < k or total % k != 0) return false;
        vector<int> subs(k, 0);
        sort(nums.rbegin(), nums.rend());
        if (nums[0] > total / k) return false; 
        return dfs(nums, subs, 0, total / k);
    }
    
    bool dfs(vector<int> & nums, vector<int> & subs, int cur, int target) {
        if (cur == nums.size()) return true;
        for(int j = 0; j < subs.size(); ++j) {
            subs[j] += nums[cur];
            if (subs[j] <= target && dfs(nums, subs, cur + 1, target))
                return true;
            subs[j] -= nums[cur];
            if(subs[j] == 0) break;
        }
        return false;
    }
};
