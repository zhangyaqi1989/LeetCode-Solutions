class Solution:
    def minimumDeviation(self, nums: List[int]) -> int:
        pq = []
        for num in nums:
            if num % 2 == 1:
                pq.append((num, num * 2))
            else:
                mx = num
                while num % 2 == 0:
                    num //= 2
                pq.append((num, mx))
        heapq.heapify(pq)
        mx = max(lo for lo, _ in pq)
        ans = mx - pq[0][0]
        while True:
            lo, hi = heapq.heappop(pq)
            heapq.heappush(pq, (lo * 2, hi))
            if lo * 2 > hi:
                break
            mx = max(mx, lo * 2)
            ans = min(ans, mx - pq[0][0])
        return ans
