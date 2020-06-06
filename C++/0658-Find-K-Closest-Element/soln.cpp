class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // find k closest element to x
        int idx = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        int lo = idx - 1, hi = idx, n = arr.size();
        vector<int> ans;
        while (ans.size() < k) {
            if (lo < 0) {
                ans.push_back(arr[hi++]);
            } else if (hi >= n) {
                ans.push_back(arr[lo--]);
            } else {
                if (x - arr[lo] <= arr[hi] - x) {
                    ans.push_back(arr[lo--]);
                } else {
                    ans.push_back(arr[hi++]);
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
