class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> counts;
        int mx_cnt = 0;
        for (auto & lst : wall) {
            int size = lst.size();
            int acc = 0;
            for(int i = 0; i < size - 1; ++i) {
                acc += lst[i];
                counts[acc] += 1;
                mx_cnt = max(mx_cnt, counts[acc]);
            }
        }
        return wall.size() - mx_cnt;
    }
};
