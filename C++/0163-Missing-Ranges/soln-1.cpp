class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        long lo = lower;
        vector<string> ans;
        for(int num : nums) {
            if (num > lo) ans.push_back(toString(lo, num - 1));
            lo = (long) num + 1 ; // + 1 is dangerous
        }
        if (upper >= lo) ans.push_back(toString(lo, upper));
        return ans;
    }
    
private:
    string toString(long lo, long hi) {
        return lo == hi ? to_string(lo) : to_string(lo) + "->" + to_string(hi);
    }
};
