class Solution {
public:
    int reversePairs(vector<int>& nums) {
        const int n = nums.size();
        return mergeSort(nums, 0, n - 1);
    }
    
private:
    int mergeSort(vector<int> & nums, int lo, int hi) {
        if (lo >= hi) return 0;
        int mid = lo + (hi - lo) / 2;
        int cnt = mergeSort(nums, lo, mid) + mergeSort(nums, mid + 1, hi);
        for(int i = lo, j = mid + 1; i <= mid; ++i) {
            while (j <= hi && nums[i] / 2.0 > nums[j]) ++j;
            cnt += j - (mid + 1);
        }
        sort(nums.begin() + lo, nums.begin() + hi + 1);
        return cnt;
    }
};
