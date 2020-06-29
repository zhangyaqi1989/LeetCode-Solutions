const int kMod = 1000000007;
class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        const int kN = nums.size();
        int hi = kN - 1;
        int ans = 0;
        for(int i = 0; i < kN; ++i) {
            while(hi >= i && nums[hi] + nums[i] > target) {
                --hi;
            }
            if(hi < i) break;
            int length = hi - i;
            ans = ((long long) ans + myPow(2, length)) % kMod;
        }
        return ans;
    }
    
    int myPow(int x, int y) {
        if(y == 0) return 1;
        else {
            int half = myPow(x, y / 2);
            int ans = (long long) half * half % kMod;
            if (y % 2 == 1) {
                ans = (long long) ans * x % kMod;
            }
            return ans;
        }
    }
};
