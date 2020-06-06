class Solution {
public:
    int countArrangement(int N) {
        vector<int> arr;
        for(int i = 1; i <= N; ++i) arr.push_back(i);
        return counts(N, arr);
    }
    
    int counts(int n, vector<int> & arr) {
        if (n <= 0) return 1;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if(arr[i] % n == 0 || n % arr[i] == 0) {
                swap(arr[i], arr[n - 1]);
                ans += counts(n - 1, arr);
                swap(arr[i], arr[n - 1]);
            }
        }
        return ans;
    }
};