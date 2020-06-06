class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        // use minmax_element
        auto result = minmax_element(A.begin(), A.end());
        // mn = *result.first, mx = *result.second
        return max(*result.second - *result.first - 2 * K, 0);
    }
};