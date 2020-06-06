class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) return false;
        int target = sum / 2;
        sort(nums.rbegin(), nums.rend());
        if (nums[0] > target) return false;
        unordered_set<int> seen;
        seen.insert(0);
        for(int num : nums) {
            unordered_set<int> temp(seen);
            for(int item : seen) {
                if (item == target || item + num == target) return true;
                temp.insert(item + num);
            }
            swap(temp, seen);
        }
        return false;
    }
};
