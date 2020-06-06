class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        nums.push_back(0);
        int i = 0, cnt = 0;
        int ans = 0;
        for (int j = 0; j < nums.size(); ++j) {
            int num = nums[j];
            if (num != nums[i]) {
                if(num == 0)
                    ans = max(ans, cnt);
                cnt = 1;
                i = j;
            } else {
                ++cnt;
            }
        }
        return ans;
    }
};