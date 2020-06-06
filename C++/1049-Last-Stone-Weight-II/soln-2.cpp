class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        unordered_set<int> dp = {0};
        for(int stone : stones) {
            unordered_set<int> next_level;
            for(int num : dp) {
                next_level.insert(num + stone);
                next_level.insert(num - stone);
            }
            swap(next_level, dp);
        }
        return abs(*min_element(dp.begin(), dp.end(), [](int x, int y) {return abs(x) < abs(y);}));
    }
};
