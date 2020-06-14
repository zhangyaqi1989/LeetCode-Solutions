class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int cnt = 0;
        for(int num : arr1) {
            if(all_of(arr2.begin(), arr2.end(), [&](int x) {return abs(x - num) > d;})) {
                ++cnt;
            }
        }
        return cnt;
    }
};
