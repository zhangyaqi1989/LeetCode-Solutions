class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        const int kN = arr.size();
        vector<int> lefts(kN, INT_MAX);
        int cur = 0;
        map<int, int> seen = {{0, -1}};
        for(int i = 0; i < kN; ++i) {
            if(i > 0) lefts[i] = lefts[i - 1];
            cur += arr[i];
            auto it = seen.find(cur - target);
            if (it != seen.end()) {
                lefts[i] = min(lefts[i], i - it->second);
            }
            seen[cur] = i;
        }
        seen.clear();
        seen[0] = kN;
        int ans = INT_MAX, memo_right = INT_MAX;
        cur = 0;
        for(int i = kN - 1; i >= 0; --i) {
            cur += arr[i];
            int right = memo_right;
            auto it = seen.find(cur - target);
            if (it != seen.end()) {
                right = min(right, it->second - i);
            }
            if (i > 0 && right != INT_MAX && lefts[i - 1] != INT_MAX) {
                ans = min(ans, right + lefts[i - 1]);
            }
            seen[cur] = i;
            memo_right = right;
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
