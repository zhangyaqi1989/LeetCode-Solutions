class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        if (nums.empty()) return 0;
        map<int, int> counter;
        for(int num : nums) ++counter[num];
        int pre = 0, cur = 0;
        int mn = counter.begin()->first, mx = counter.rbegin()->first;
        for(int num = mn; num <= mx; ++num) {
            int cnt = counter[num];
            int temp = cur;
            cur = max(cur, pre + num * cnt);
            pre = temp;
        }
        return max(pre, cur);
    }
};
