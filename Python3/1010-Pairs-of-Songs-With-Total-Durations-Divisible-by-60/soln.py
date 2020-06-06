class Solution:
    def numPairsDivisibleBy60(self, time: List[int]) -> int:
        count = collections.Counter(time)
        ans = 0
        for t1 in range(1, 501):
            for t2 in range(t1, 501):
                if count[t1] and count[t2] and (t1 + t2) % 60 == 0:
                    if t1 != t2:
                        ans += count[t1] * count[t2]
                    else:
                        ans += count[t1] * (count[t2] - 1) // 2
        return ans
