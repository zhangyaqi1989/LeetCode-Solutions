class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        int min = *min_element(A.begin(), A.end());
        int max = *max_element(A.begin(), A.end());
        if (max - min <= 2*K) return 0;
        else return max - min - 2*K;
    }
};