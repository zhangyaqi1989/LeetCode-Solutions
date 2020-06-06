class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return to_string(nums[0]);
        else if (n == 2) return to_string(nums[0]) + "/" + to_string(nums[1]);
        else {
            string ans = "";
            for(int i = 1; i < n; ++i) {
                ans += to_string(nums[i]);
                if (i != n - 1) ans += "/";
            }
            ans = to_string(nums[0]) + "/(" + ans + ")";
            return ans;
        }
    }
};
