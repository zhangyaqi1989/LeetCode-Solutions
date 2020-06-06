class Solution {
public:
    int maxProduct(vector<int>& nums) {
        long long cur_mx = 1;
        long long cur_mn = 1;
        long long mx = LLONG_MIN;
        for(int num : nums) {
            long long new_cur_mx = max((long long) num, max(cur_mx * num, cur_mn * num));
            long long new_cur_mn = min((long long) num, min(cur_mx * num, cur_mn * num));
            cur_mx = new_cur_mx;
            cur_mn = new_cur_mn;
            mx = max(mx, max(cur_mx, cur_mn));
        }
        return (int) mx;
    }
};
