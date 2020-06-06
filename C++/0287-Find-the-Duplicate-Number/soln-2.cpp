class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int lo = 0, hi = (int) nums.size() - 1;
        while(lo < hi) {
            int mid = lo + (hi - lo) / 2;
            int cnt = 0;
            for(int num : nums) {
                if (num <= mid) ++cnt;
            }
            if(cnt > mid) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
    }
};
