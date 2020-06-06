class Solution {
    public int maxProfit(int[] prices) {
        // at most one transaction
        if (prices.length == 0) return 0;
        int min_price = prices[0];
        int profile = 0;
        for(int price : prices) {
            min_price = Math.min(price, min_price);
            profile = Math.max(profile, price - min_price);
        }
        return profile;
    }
}