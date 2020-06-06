class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        const int kN = arr.size();
        int lo = 0;
        for(int i = 0; i < kN; ++i) {
            if (arr[i] != arr[lo]) {
                if (i - lo > kN / 4) {
                    return arr[lo];
                }
                lo = i;
            }
        }
        return arr.back();
    }
};
