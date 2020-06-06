class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> cums;
        cums[0] = 1;
        int cum = 0;
        int ans = 0;
        for(auto num : nums) {
            cum += num;
            auto it = cums.find(cum - k);
            if(it != cums.end()) ans += it->second;
            cums[cum]++;
        }
        return ans;
    }
};
