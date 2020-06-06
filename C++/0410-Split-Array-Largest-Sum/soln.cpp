class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        // minimize the sum
        long long lo = *min_element(nums.begin(), nums.end()), hi = accumulate(nums.begin(), nums.end(), 0LL);
        // cout << lo << " " << hi << endl;
        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            cout << mid << " " << valid(nums, m, mid) << endl;
            if (valid(nums, m, mid)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
    }
    
    bool valid(vector<int> & nums, int m, long long mx) {
        int cnt = 1;
        long long cur = 0LL;
        for(int num : nums) {
            if (num > mx) return false;
            if (cur + num > mx) {
                if (++cnt > m) return false;
                cur = num;
            } else {
                cur += num;
            }
            
        }
        return true;
    }
};
