class Solution {
    public int maxProfit(int[] prices, int fee) {
        int hold = -10000000, not_hold = 0;
        for(int price : prices) {
            int new_hold = Math.max(hold, not_hold - price);
            int new_not_hold = Math.max(not_hold, hold + price - fee);
            hold = new_hold;
            not_hold = new_not_hold;
        }
        return not_hold;
    }
}
