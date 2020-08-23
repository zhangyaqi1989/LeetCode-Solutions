class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        const int kN = arr.size();
        for(int i = 0; i < kN - 2; ++i) {
            if(arr[i] % 2 == 1 && arr[i + 1] % 2 == 1 && arr[i + 2] % 2 == 1) return true;
        }
        return false;
    }
};
