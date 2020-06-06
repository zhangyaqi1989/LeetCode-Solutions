class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
        vector<double> nums;
        double lo = 0, hi = 1;
        int n = A.size();
        for(int num : A) nums.push_back(num);
        while (true) {
            double mid = (lo + hi) / 2;
            vector<int> idxes;
            int cnt = 0;
            for(int i = 0; i < n; ++i) {
                int idx = upper_bound(nums.begin(), nums.end(), nums[i] / mid) - nums.begin();
                idxes.push_back(idx);
                cnt += n - idx;
            }
            if (cnt < K) {
                lo = mid;
            } else if (cnt > K) {
                hi = mid;
            } else {
                double mx = 0;
                int ans = 0;
                for(int i = 0; i < n; ++i) {
                    int idx = idxes[i];
                    if (idx < n) {
                        if (nums[i] / nums[idx] > mx) {
                            mx = nums[i] / nums[idx];
                            ans = i;
                        }
                    }
                }
                return {nums[ans], nums[idxes[ans]]};
            }
        }
    }
};
