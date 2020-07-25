class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int pres [] = {1, 0};
        int cur = 0;
        int ans = 0;
        for(int num : arr) {
            cur = (cur + num) % 2;
            ans = (long long) (ans + pres[1 - cur]) % 1000000007;
            ++pres[cur];
        }
        return ans;
    }
};
