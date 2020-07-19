class Solution {
    public int numWaterBottles(int nfulls, int exchange) {
        int nempties = 0;
        int ndrinks = 0;
        while(nfulls > 0) {
            ndrinks += nfulls;
            nempties += nfulls;
            nfulls = 0;
            if(nempties >= exchange) {
                nfulls += nempties / exchange;
                nempties %= exchange;
            }
        }
        return ndrinks;
    }
}
