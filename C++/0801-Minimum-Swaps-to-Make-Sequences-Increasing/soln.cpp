class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        int n = A.size(), swap = 1, noswap = 0;
        for(int i = 1; i < n; ++i) {
            int temp_swap = INT_MAX, temp_noswap = INT_MAX;
            if (A[i - 1] < A[i] && B[i - 1] < B[i]) {
                temp_swap = min(temp_swap, swap + 1);
                temp_noswap = min(temp_noswap, noswap);
            }
            if (A[i - 1] < B[i] && B[i - 1] < A[i]) {
                temp_swap = min(temp_swap, noswap + 1);
                temp_noswap = min(temp_noswap, swap);
            }
            swap = temp_swap;
            noswap = temp_noswap;
        }
        return min(swap, noswap);
    }
};
