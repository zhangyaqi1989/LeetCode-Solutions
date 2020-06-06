class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
        // binary search
        double lo = 0.0, hi = 1.0;
        sort(A.begin(), A.end());
        int n = A.size();
        int a = 0, b = 0;
        while (lo < hi) {
            double mid = (lo + hi) / 2.0;
            // want to count number of fractions while is less than or equal to mid
            int cnt = 0;
            a = 0, b = 0;
            for(int i = 0; i < n; ++i) {
                int nume = A[i];
                int min_deno = ceil(nume / mid);
                int idx = lower_bound(A.begin(), A.end(), min_deno) - A.begin();
                // cout << nume << " " << idx << endl;
                // if (idx < n) cout << nume << " " << A[idx] << endl;
                if (idx < n) {
                    if(a == 0) {
                        a = nume;
                        b = A[idx];
                    } else {
                        if (static_cast<double>(nume) / A[idx] > static_cast<double>(a) / b) {
                            a = nume;
                            b = A[idx];
                        }
                    }                    
                }
                cnt += n - idx;
            }
            if (cnt < K) {
                lo = mid;
            } else if (cnt == K) {
                return {a, b};
            } else {
                hi = mid;
            }
        }
        return {0, 0};
    }
};
