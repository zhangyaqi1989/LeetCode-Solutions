class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> counter;
        int n = nums.size();
        const int N = 50000;
        vector<int> low_idxes(N, -1);
        vector<int> hi_idxes(N, -1);
        for(int i = 0; i < n; ++i) {
            int num = nums[i];
            counter[num]++;
            if(low_idxes[num] == -1) {
                low_idxes[num] = i;
            }
            hi_idxes[num] = i;
        }
        int mx_fre = 0;
        for(auto & it : counter) {
            if(it.second > mx_fre) {
                mx_fre = it.second;
            }
        }
        int ans = n;
        for(auto & it : counter) {
            if(it.second == mx_fre) {
                int num = it.first;
                int hi = hi_idxes[num], low = low_idxes[num];
                if(hi - low + 1 < ans) ans = hi - low + 1;
            }
        }
        return ans;
    }
};
