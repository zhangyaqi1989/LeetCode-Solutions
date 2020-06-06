class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        // minimum length of s
        int lo = 0;
        int window = 0;
        const int INF = nums.size() + 1;
        int len = INF;
        for(int i = 0; i < nums.size(); ++i) {
            window += nums[i];
            while (window - nums[lo] >= s) {
                window -= nums[lo++];
            }
            if (window >= s) {
                len = min(len, i - lo + 1);
            }
        }
        return len == INF ? 0 : len; 
    }
};
