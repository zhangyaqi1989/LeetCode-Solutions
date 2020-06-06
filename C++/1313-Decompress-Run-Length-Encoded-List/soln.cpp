class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        const int kN = nums.size();
        vector<int> ans;
        for(int i = 0; i < kN; i += 2) {
            int cnt = nums[i], num = nums[i + 1];
            for(int j = 0; j < cnt; ++j) ans.push_back(num);
        }
        return ans;
    }
};
