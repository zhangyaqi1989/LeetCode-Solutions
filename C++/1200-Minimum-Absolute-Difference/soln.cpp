class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> ans;
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int min_diff = arr.back() - arr.front();
        for(int i = 1; i < n; ++i) {
            if (arr[i] - arr[i - 1] < min_diff) {
                min_diff = arr[i] - arr[i - 1];
                ans.clear();
                ans.push_back({arr[i - 1], arr[i]});
            } else if (arr[i] - arr[i - 1] == min_diff) {
                ans.push_back({arr[i - 1], arr[i]});
            }
        }
        return ans;
    }
};
