class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int cnt = 0;
        const size_t kN = arr.size();
        for(size_t i = 0; i < kN; ++i) {
            for(size_t j = i + 1; j < kN; ++j) {
                for(size_t k = j + 1; k < kN; ++k) {
                    cnt += abs(arr[i] - arr[j]) <= a && abs(arr[j] - arr[k]) <= b && abs(arr[i] - arr[k]) <= c;
                }
            }
        }
        return cnt;
    }
};
