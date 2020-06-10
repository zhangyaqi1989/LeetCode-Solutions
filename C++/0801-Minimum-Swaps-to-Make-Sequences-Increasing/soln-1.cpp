class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        // in the same dimension
        const int kN = A.size();
        int swap = 1, no_swap = 0;
        const int kInf = 5000;
        for(int i = 1; i < kN; ++i) {
            int new_swap = kInf, new_no_swap = kInf;
            if (A[i] > A[i - 1] && B[i] > B[i - 1]) {
                new_no_swap = min(new_no_swap, no_swap);
                new_swap = min(new_swap, swap + 1);
            }
            if (A[i] > B[i - 1] && B[i] > A[i - 1]) {
                new_no_swap = min(new_no_swap, swap);
                new_swap = min(new_swap, 1 + no_swap);
            }
            swap = new_swap;
            no_swap = new_no_swap;
        }
        return min(swap, no_swap);
    }
};
