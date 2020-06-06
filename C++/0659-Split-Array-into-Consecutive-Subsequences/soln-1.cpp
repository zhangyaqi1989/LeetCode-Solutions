class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> lefts;
        unordered_map<int, int> ends;
        for(int num : nums) ++lefts[num];
        for(int num : nums) {
            if (lefts[num] == 0) continue;
            --lefts[num];
            if (ends[num - 1] > 0) {
                --ends[num - 1];
                ++ends[num];
            } else if (lefts[num + 1] > 0 && lefts[num + 2] > 0) {
                --lefts[num + 1];
                --lefts[num + 2];
                ++ends[num + 2];
            } else {
                return false;
            }
        }
        return true;
    }
};
