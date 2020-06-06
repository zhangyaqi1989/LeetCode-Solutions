class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        // multiset
        const int n = nums.size();
        multiset<int> window(nums.begin(), nums.begin() + k);
        auto mid = next(window.begin(), k / 2);
        vector<double> medians;
        for(int i = k;; ++i) {
            if (k % 2) medians.push_back(*mid);
            else medians.push_back(*mid / 2.0 + *prev(mid) / 2.0);
            
            if (i == n) return medians;
            window.insert(nums[i]);
            if (nums[i] < *mid) {
                --mid;
            }
            if (nums[i - k] <= *mid) {
                ++mid;
            }
            window.erase(window.lower_bound(nums[i - k]));
        }
        return medians;
    }
};
