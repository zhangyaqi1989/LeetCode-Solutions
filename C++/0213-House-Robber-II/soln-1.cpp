class Solution {
public:
    int rob(vector<int>& nums) {
        const int kN = nums.size();
        if (kN == 0) return 0;
        else if (kN == 1) return nums[0];
        else return max(Solve(nums, 0, kN - 2), Solve(nums, 1, kN - 1));
    }
    
private:
    int Solve(const vector<int> & nums, int lo, int hi) {
        const int kN = hi - lo + 1;
        if (kN <= 0) return 0;
        else if (kN == 1) return nums[lo];
        else if (kN == 2) return max(nums[lo], nums[lo + 1]);
        else {
            int pre = nums[lo], cur = max(nums[lo], nums[lo + 1]);
            for(int i = lo + 2; i <= hi; ++i) {
                int new_cur = max(pre + nums[i], cur);
                pre = cur;
                cur = new_cur;
            }
            return max(pre, cur);
        }
    }
};
