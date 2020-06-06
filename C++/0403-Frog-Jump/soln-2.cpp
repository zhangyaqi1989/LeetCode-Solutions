class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_set<int> has_stones(stones.begin(), stones.end());
        int target = stones.back();
        unordered_map<string, bool> memo;
        return dfs(0, 0, target, has_stones, memo);
    }
    
private:
    bool dfs(int pos, int step, int target, unordered_set<int> & has_stones, unordered_map<string, bool> & memo) {
        if (pos == target) return true;
        string code = to_string(pos) + " " + to_string(step);
        auto it = memo.find(code);
        if (it != memo.end()) return it->second;
        bool can = false;
        for(int d = -1; d < 2; ++d) {
            int new_step = step + d;
            if (new_step <= 0 || has_stones.find(pos + new_step) == has_stones.end()) continue;
            if (dfs(pos + new_step, new_step, target, has_stones, memo)) {
                can = true;
                break;
            }
        }
        memo.insert({code, can});
        return can;
    }
};
