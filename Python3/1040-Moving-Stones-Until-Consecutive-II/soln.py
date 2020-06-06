class Solution:
    def numMovesStonesII(self, stones: List[int]) -> List[int]:
        def helper():
            n = len(stones)
            if (stones[-2] - stones[0] == n - 2 and stones[-1] - stones[-2] > 2) or (stones[-1] - stones[1] == n - 2 and stones[1] - stones[0] > 2):
                return 2
            dq = collections.deque()
            ans = 0
            for num in stones:
                dq.append(num)
                while dq[-1] - dq[0] + 1 > n:
                    dq.popleft()
                ans = max(ans, len(dq))
            return n - ans
            
        stones.sort()
        n = len(stones)
        mx = 0
        for i in range(n - 1):
            a, b = stones[i], stones[i + 1]
            mx += max(b - a - 1, 0)
        mx -= max(min(stones[1] - stones[0] - 1, stones[-1] - stones[-2] - 1), 0)
        return helper(), mx
        
