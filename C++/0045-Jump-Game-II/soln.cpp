class Solution {
public:
    int jump(vector<int>& nums) {
        int start = 0, end = 0, n = nums.size(), step = 0;
        while (end < n - 1)
        {
            ++step;
            int max_end = end + 1;
            for(int i = start; i <= end; ++i)
            {
                max_end = max(max_end, i + nums[i]);
                if(max_end >= n - 1) return step;
            }
            start = end + 1;
            end = max_end;
        }
        return step;
        
    }
};