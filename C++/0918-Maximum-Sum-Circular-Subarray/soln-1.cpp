class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        // two possibilities: max subarray, sum - min subarray
        // if (all_of(A.begin(), A.end(), [](int x){return x < 0;})) return *max_element(A.begin(), A.end());
        int mx = A[0], mn = A[0];
        int cur_mn = 0, cur_mx = 0;
        int sum = 0;
        for(int num : A) {
            sum += num;
            cur_mn = min(num, cur_mn + num);
            mn = min(mn, cur_mn);
            cur_mx = max(num, cur_mx + num);
            mx = max(mx, cur_mx);
        }
        // cout << mx << " " << mn << " " << sum << endl;
        return mx < 0 ? mx : max(sum - mn, mx);
    }
};
