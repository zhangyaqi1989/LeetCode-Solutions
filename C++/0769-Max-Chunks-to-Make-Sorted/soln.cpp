auto desyncio = []()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

// Greedy

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int cnt = 0;
        int maxSeen = -1;
        for(int i = 0; i < n; i++) {
            maxSeen = max(maxSeen, arr[i]);
            if (maxSeen == i) cnt += 1;
        }
        return cnt;
    }
};
