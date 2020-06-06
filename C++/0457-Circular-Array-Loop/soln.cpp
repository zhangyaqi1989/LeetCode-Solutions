class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int mn = 2000;
        int n = nums.size();
        for(int i = 0; i < n; ++i) {
            int mark = mn + i;
            int j = i;
            int num = nums[i];
            while (nums[j] < mn && num * nums[j] > 0 && nums[j] % n != 0) {
                int jump = nums[j];
                nums[j] = mark;
                j = (j + jump) % n;
                if (j < 0) j += n;
            }
            if (nums[j] == mark) return true;
        }
        return false;
    }
};
