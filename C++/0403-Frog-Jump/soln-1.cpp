class Solution {
public:
    bool canCross(vector<int>& stones) {
        memo.clear();
        return helper(stones, 0, 0);
    }
    
    bool helper(vector<int> & stones, int pos, int k) {
        int key = k | (pos << 11);
        auto it = memo.find(key);
        if (it != memo.end()) return it->second;
        int n = stones.size();
        bool ans = false;
        for(int i = pos + 1; i < n; ++i) {
            int gap = stones[i] - stones[pos];
            if (gap < k - 1) continue;
            else if (gap > k + 1) {
                memo[key] = false;
                return false;
            } else {
                if (helper(stones, i, gap)) {
                    memo[key] = true;
                    return true;
                }
            }
        }
        memo[key] = (pos == n - 1);
        return pos == n - 1;
    }
    
private:
    unordered_map<int, bool> memo;
};
