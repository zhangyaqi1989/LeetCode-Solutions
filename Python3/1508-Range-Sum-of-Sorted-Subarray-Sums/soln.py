class Solution:
    def rangeSum(self, nums: List[int], n: int, left: int, right: int) -> int:
        pres = [0]
        subs = []
        for num in nums:
            pres.append(pres[-1] + num)
            for i in range(len(pres) - 1):
                subs.append(pres[-1] - pres[i])
        subs.sort()
        return sum(subs[i - 1] for i in range(left, right + 1)) % 1000000007
