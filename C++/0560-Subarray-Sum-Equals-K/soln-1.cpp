class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> seen;
        seen.insert({0, 1});
        int cur = 0;
        int cnt = 0;
        for(int num : nums) {
            cur += num;
            auto it = seen.find(cur - k);
            if (it != seen.end()) cnt += it->second;
            ++seen[cur];
        }
        return cnt;
    }
};
