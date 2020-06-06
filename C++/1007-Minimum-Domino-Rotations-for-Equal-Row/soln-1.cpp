class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        const int kN = A.size();
        vector<int> counter_a(7), counter_b(7), same(7);
        for(int i = 0; i < kN; ++i) {
            ++counter_a[A[i]];
            ++counter_b[B[i]];
            if (A[i] == B[i]) ++same[A[i]];
        }
        for(int num = 1; num < 7; ++num) {
            if (counter_a[num] + counter_b[num] - same[num] == kN) {
                return kN - max(counter_a[num], counter_b[num]);
            }
        }
        return -1;
    }
};
