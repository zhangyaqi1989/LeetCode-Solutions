class Solution {
public:
    int missingNumber(vector<int>& arr) {
        const int kN = arr.size();
        int d = (arr.back() - arr[0]) / kN;
        for(int i = 0; i < kN - 1; ++i) {
            if (arr[i + 1] != arr[i] + d) {
                return arr[i] + d;
            }
        }
        return arr[0];
    }
};
