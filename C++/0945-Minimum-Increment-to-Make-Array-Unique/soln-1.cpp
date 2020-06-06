class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        if (A.empty()) return 0;
        sort(A.begin(), A.end());
        int min_slot = A[0], moves = 0;
        const int kN = A.size();
        for(int i = 0; i < kN; ++i) {
            if (A[i] < min_slot) {
                moves += min_slot - A[i];
            }
            min_slot = max(min_slot + 1, A[i] + 1);
        }
        return moves;
    }
};
