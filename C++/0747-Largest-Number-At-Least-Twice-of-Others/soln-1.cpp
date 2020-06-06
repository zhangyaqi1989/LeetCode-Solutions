class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int first = -1, second = -1, idx = -1;
        for(int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            if (num > first) {
                second = first;
                first = num;
                idx = i;
            } else if (num != first && num > second) second = num;
        }
        return first >= 2 * second ? idx : -1;
    }
};
