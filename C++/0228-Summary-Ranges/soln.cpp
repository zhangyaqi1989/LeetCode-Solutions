class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if (nums.empty()) return ans;
        int lo = nums[0], hi = nums[0], n = nums.size();
        for(int i = 1; i < n; ++i) {
            if (hi + 1 < nums[i]) {
                ans.push_back(rangeToString(lo, hi));
                lo = hi = nums[i];
            } else {
                hi = nums[i];
            }
        }
        ans.push_back(rangeToString(lo, hi));
        return ans;
    }
    
    string rangeToString(int lo, int hi) {
        if (lo == hi) return to_string(lo);
        else return to_string(lo) + "->" + to_string(hi);
    }
};
