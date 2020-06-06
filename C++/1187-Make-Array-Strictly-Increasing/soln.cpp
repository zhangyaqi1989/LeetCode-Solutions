class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> dp;
        dp[-1] = 0;
        sort(arr2.begin(), arr2.end());
        for(int num : arr1) {
            unordered_map<int, int> temp;
            for (auto & p : dp) {
                int key = p.first, value = p.second;
                if (num > key) {
                    temp[num] = min(value, temp.find(num) == temp.end() ? INT_MAX : temp[num]);
                }
                auto it = upper_bound(arr2.begin(), arr2.end(), key);
                if (it != arr2.end()) {
                    temp[*it] = min(value + 1, temp.find(*it) == temp.end() ? INT_MAX : temp[*it]);
                }
            }
            swap(dp, temp);
        }
        if (!dp.empty()) {
            int ans = INT_MAX;
            for (auto & p : dp) {
                if (p.second < ans) ans = p.second;
            }
            return ans;
        }
        return -1;
    }
};
