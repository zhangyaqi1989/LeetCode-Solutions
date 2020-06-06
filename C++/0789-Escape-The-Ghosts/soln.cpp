class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        int distance = abs(target[0]) + abs(target[1]);
        int t0 = target[0], t1 = target[1];
        for(auto & ghost : ghosts) {
            int a = ghost[0], b = ghost[1];
            if (abs(a - t0) + abs(b - t1) <= distance) return false;
        }
        return true;
    }
};
