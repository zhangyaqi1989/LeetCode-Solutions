class Solution {
public:
    int minCostToMoveChips(vector<int>& chips) {
        int evens = 0, odds = 0;
        for(int chip : chips) {
            if (chip & 1) ++odds;
            else ++evens;
        }
        return min(odds, evens);
    }
};
