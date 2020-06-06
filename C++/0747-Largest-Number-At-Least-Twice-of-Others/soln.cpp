class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        // 
        int first = INT_MIN, second = INT_MIN;
        int idx = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            if (num > first) {
                idx = i;
                int temp = first;
                first = num;
                second = temp;
            } else if (num > second)
                second = num;
        }
        return first - second * 2 >= 0 ? idx : -1;
    }
};