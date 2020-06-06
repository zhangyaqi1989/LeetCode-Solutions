class Solution {
    public int maxProfit(int[] prices) {
        int hold = Integer.MIN_VALUE, cool = Integer.MIN_VALUE, free = 0;
        for(int price : prices) {
            int new_hold = Math.max(hold, free - price);
            int new_cool = hold + price;
            int new_free = Math.max(free, cool);
            hold = new_hold;
            cool = new_cool;
            free = new_free;
        }
        return Math.max(cool, free);
    }
}
