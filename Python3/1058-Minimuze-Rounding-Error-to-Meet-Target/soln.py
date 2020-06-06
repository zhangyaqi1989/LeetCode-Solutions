class Solution:
    def minimizeError(self, prices: List[str], target: int) -> str:
        temp = [(price - math.floor(price), math.floor(price), math.ceil(price)) for price in map(float, prices)]
        prices = []
        for num, lo, hi in temp:
            if lo == hi:
                target -= lo
            else:
                prices.append((num, lo, hi))
        prices.sort()
        lower = sum(lo for _, lo, _ in prices)
        upper = sum(hi for _, _, hi in prices)
        if lower > target or target > upper:
            return "-1"
        cnt = upper - target
        ans = 0
        for num, lo, hi in prices:
            if cnt > 0:
                ans += num
                cnt -= 1
            else:
                ans += 1.0 - num
        return "{:.3f}".format(ans)
