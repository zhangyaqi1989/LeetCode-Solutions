class Solution {
    public int minCostToMoveChips(int[] chips) {
        int evens = 0, odds = 0;
        for(int chip : chips) {
            if (chip % 2 == 1) ++odds;
            else ++evens;
        }
        return Math.min(odds, evens);
    }
}
