class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        if (costs.empty()) return 0;
        int red = costs[0][0], blue = costs[0][1], green = costs[0][2], n = costs.size();
        for(int i = 1; i < n; ++i) {
            int new_red = min(blue, green) + costs[i][0];
            int new_blue = min(red, green) + costs[i][1];
            int new_green = min(red, blue) + costs[i][2];
            red = new_red;
            blue = new_blue;
            green = new_green;
        }
        return min(red, min(blue, green));
    }
};
