class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> window;
        int lo = 0;
        int n = nums.size();
        int ans = -1;
        for(int i = 0; i < n; ++i) {
            window.insert(nums[i]);
            while((*window.rbegin()) - (*window.begin()) > limit) {
                window.erase(window.find(nums[lo++]));
            }
            ans = max(ans, i - lo + 1);
        }
        return ans;
    }
};
