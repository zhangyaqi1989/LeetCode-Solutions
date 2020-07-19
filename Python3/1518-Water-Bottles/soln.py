class Solution:
    def numWaterBottles(self, numBottles: int, numExchange: int) -> int:
        nempties = 0
        ndrinks = 0
        while numBottles:
            ndrinks += numBottles
            nempties += numBottles
            numBottles = 0
            if nempties >= numExchange:
                numBottles = nempties // numExchange
                nempties %= numExchange
        return ndrinks
