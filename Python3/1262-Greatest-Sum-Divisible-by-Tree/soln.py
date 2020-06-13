class Solution:
    def maxSumDivThree(self, nums: List[int]) -> int:
        ones = []
        twos = []
        ans = 0
        for num in nums:
            ans += num
            if num % 3 == 1:
                ones.append(num)
            elif num % 3 == 2:
                twos.append(num)
        if ans % 3 == 0:
            return ans
        ones.sort()
        twos.sort()
        if ans % 3 == 1:
            best = 0
            if ones:
                best = ans - ones[0]
            if len(twos) >= 2:
                best = max(best, ans - twos[0] - twos[1])
        else: # ans % 3 == 2:
            best = 0
            if twos:
                best = ans - twos[0]
            if len(ones) >= 2:
                best = max(best, ans - ones[0] - ones[1])
        return best
