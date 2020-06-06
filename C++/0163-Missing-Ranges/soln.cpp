typedef long long ll;
class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> ans;
        ll miss = lower;
        for(int num : nums) {
            if (num == miss) {
                miss = num + 1LL;
            } else if (num > miss) {
                ans.push_back(rangeToString(miss, num - 1));
                miss = num + 1LL;
            }
        }
        if (miss <= upper) ans.push_back(rangeToString(miss, upper));
        return ans;
    }
    
    string rangeToString(ll lo, ll hi) {
        if (lo == hi) return to_string(lo);
        return to_string(lo) + "->" + to_string(hi);
    }
};
