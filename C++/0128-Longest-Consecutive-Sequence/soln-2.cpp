// x, x + 1, x + 2, ..., x + k, k
// [100, 4, 200, 1, 3, 2] -> 4: 1, 2, 3, 4
// HashSet to make isin() query constant time
// for a sequence, we only check when we at the head of a sequence
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> vals(nums.begin(), nums.end());
        int ans = 0;
        for(int num : nums) {
            if (vals.find(num - 1) == vals.end()) { // not found
                // num
                int len = 1;
                ++num;
                while (vals.find(num) != vals.end()) {
                    ++num;
                    ++len;
                }
                ans = max(ans, len);
            }
        }
        return ans;
    }
};
