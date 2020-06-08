class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        int median = arr[(static_cast<int>(arr.size()) - 1) / 2];
        sort(arr.begin(), arr.end(), [&](int a, int b) {
            return abs(a - median) == abs(b - median) ? a > b : abs(a - median) > abs(b - median);
        });
        vector<int> ans(arr.begin(), arr.begin() + k);
        return ans;
    }
};
