class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int lo = 0, hi = n - 1;
        while (lo < hi) {
            int m = numbers[lo] + numbers[hi];
            if (m == target) {
                return {lo + 1, hi + 1};
            } else if (m < target) {
                ++lo;
            } else {
                --hi;
            }
        }
        return {};
    }
};
