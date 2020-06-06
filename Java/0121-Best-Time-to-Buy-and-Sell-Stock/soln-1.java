class Solution {
    public int maxProfit(int[] prices) {
        int ans = 0;
        int low_price = Integer.MAX_VALUE;
        for(int price : prices) {
            low_price = Math.min(price, low_price);
            ans = Math.max(ans, price - low_price);
        }
        return ans;
    }
}
