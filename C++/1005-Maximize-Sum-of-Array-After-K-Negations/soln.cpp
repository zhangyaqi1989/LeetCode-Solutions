class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        sort(A.begin(), A.end());
        int n = A.size();
        for(int i = 0; i < n, K > 0; ++i, --K) {
            if (A[i] < 0) A[i] = -A[i];
            else break;
        }
        int mn = *min_element(A.begin(), A.end());
        return accumulate(A.begin(), A.end(), 0) - (K % 2) * mn * 2;
    }
};
