class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // majority vote
        int cnt = 0;
        int major = 0;
        for (auto num : nums)
        {
            if (cnt == 0)
            {
                major = num;
                cnt++;
            }
            else
            {
                if (num == major) cnt++;
                else cnt--;
            }
        }
        return major;
    }
};