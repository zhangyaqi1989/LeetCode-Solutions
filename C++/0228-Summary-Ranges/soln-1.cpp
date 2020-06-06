class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        const int n = nums.size();
        if (n == 0) return {};
        int lo = nums[0], hi = nums[0];
        vector<string> ans;
        for(int num : nums) {
            if (num > hi + 1) {
                ans.push_back(convertToStr(lo, hi));
                lo = num;
                hi = num;
            } else {
                hi = num;
            }
        }
        ans.push_back(convertToStr(lo, hi));
        return ans;
    }

private:
    string convertToStr(int lo, int hi) {
        if (lo == hi) return to_string(lo);
        else return to_string(lo) + "->" + to_string(hi);
    }
};
