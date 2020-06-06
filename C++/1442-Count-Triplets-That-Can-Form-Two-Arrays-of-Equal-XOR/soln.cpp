class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> memo = {{0, 1}};
        int ans = 0;
        int cur = 0;
        for(int j = 0; j < n; ++j) {
            cur ^= arr[j];
            int temp = cur;
            for(int k = j + 1; k < n; ++k) {
                temp ^= arr[k];
                int b = temp ^ cur;
                int need = cur ^ b;
                auto it = memo.find(need);
                if(it != memo.end()) ans += it->second; 
            }
            ++memo[cur];
        }
        return ans;
    }
};
