class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int n = nums.size();
        int bits [32] = {0};
        for(int num : nums) {
            for(int i = 0; i < 32; ++i) {
                if ((num >> i) & 1) ++bits[i];
            }
        }
        int cnt = 0;
        for(int num : bits) cnt += num * (n - num);
        return cnt;
    }
};
