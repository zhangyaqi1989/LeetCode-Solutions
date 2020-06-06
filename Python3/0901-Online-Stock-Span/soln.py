from functools import lru_cache
class StockSpanner:

    def __init__(self):
        self.prices = []
        
    @lru_cache(None)
    def _span(self, i):
        if i == 0:
            return 1
        else:
            if self.prices[i - 1] > self.prices[i]:
                return 1
            else:
                cnt = self._span(i - 1)
                ans = cnt + 1
                j = i - cnt - 1
                while j >= 0 and self.prices[j] <= self.prices[i]:
                    j -= 1
                    ans += 1
                return ans

    def next(self, price):
        """
        :type price: int
        :rtype: int
        """
        self.prices.append(price)
        return self._span(len(self.prices) - 1)



# Your StockSpanner object will be instantiated and called as such:
# obj = StockSpanner()
# param_1 = obj.next(price)
