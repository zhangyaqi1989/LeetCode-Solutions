class Solution {
public:
    int longestSubsequence(vector<int>& arr, int diff) {
        unordered_map<int, int> seen;
        int ans = 1;
        for(int num : arr) {
            auto it = seen.find(num - diff);
            if(it != seen.end()) {
                int cnt = it->second;
                seen.erase(it);
                seen[num] = max(seen[num], cnt + 1);
                ans = max(ans, cnt + 1);
            } else {
                seen[num] = max(seen[num], 1);
            }
        }
        return ans;
    }
};
