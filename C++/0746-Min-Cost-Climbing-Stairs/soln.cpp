class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // int first = cost[0], second = min(cost[0], cost[1]);
        int first = 0, second = 0;
        for(int i = 0; i < cost.size() + 1; ++i)
        {
            int temp = second;
            second = min(second + cost[i - 1], first + cost[i - 2]);
            first = temp;
        }
        return second;
    }
};