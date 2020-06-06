class Solution {
    public int maxProfit(int[] prices) {
        int free1 = 0, free2 = Integer.MIN_VALUE, hold1 = Integer.MIN_VALUE, hold2 = Integer.MIN_VALUE;
        for(int price : prices) {
            free1 = Math.max(free1, hold1 + price);
            hold1 = Math.max(hold1, -price);
            free2 = Math.max(free2, hold2 + price);
            hold2 = Math.max(hold2, free1 - price);
        }
        return Math.max(free1, free2);
    }
}
