class Solution {
public:
    int minDistance(int height, int width, vector<int>& tree, vector<int>& squirrel, vector<vector<int>>& nuts) {
        int tx = tree[0], ty = tree[1], sx = squirrel[0], sy = squirrel[1];
        int repeat = 0;
        for(auto & nut : nuts) repeat += 2 * (abs(tx - nut[0]) + abs(ty - nut[1]));
        int mn = INT_MAX;
        for(auto & nut : nuts) {
            int temp = repeat + (abs(sx - nut[0]) + abs(sy - nut[1])) - (abs(tx - nut[0]) + abs(ty - nut[1]));
            mn = min(temp, mn);
        }
        return mn;
    }
};
