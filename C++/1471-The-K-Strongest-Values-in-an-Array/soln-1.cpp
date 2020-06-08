class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int median = arr[(n - 1) / 2];
        vector<int> ans;
        int i = 0, j = n - 1;
        while(k-- > 0) {
            if(median - arr[i] > arr[j] - median) ans.push_back(arr[i++]);
            else ans.push_back(arr[j--]);
        }
        return ans;
    }
};
