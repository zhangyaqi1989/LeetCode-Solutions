class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> left, ends;
        for(int num : nums) ++left[num];
        for(int num : nums) {
            if (!left[num]) continue;
            --left[num];
            if (ends[num - 1]) {
                --ends[num - 1];
                ++ends[num];
            } else if (left[num + 1] && left[num + 2]) {
                --left[num + 1];
                --left[num + 2];
                ++ends[num + 2];
            } else {
                return false;
            }
        }
        return true;
    }
};
