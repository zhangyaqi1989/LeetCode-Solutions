class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        int n = arr.size();
        nth_element(arr.begin(), arr.begin() + (n - 1)/2, arr.end());
        int median = arr[(n - 1)/2];
        nth_element(arr.begin(), arr.begin() + k, arr.end(), [&](int a, int b) {
           return abs(a - median) == abs(b - median) ? a > b : abs(a - median) > abs(b - median); 
        });
        arr.resize(k);
        return arr;
    }
};
