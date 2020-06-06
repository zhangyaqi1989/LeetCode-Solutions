from fractions import Fraction
class Solution:
    def kthSmallestPrimeFraction(self, A: List[int], K: int) -> List[int]:
        pq = []
        n = len(A)
        for i in range(n - 1):
            pq.append((Fraction(A[i], A[n - 1]), i, n - 1))
        heapq.heapify(pq)
        cnt = 1
        while cnt < K:
            _, row, col = heapq.heappop(pq)
            if col - 1 > row:
                heapq.heappush(pq, (Fraction(A[row], A[col - 1]), row, col - 1))
            cnt += 1
        ans = heapq.heappop(pq)[0]
        return [ans.numerator, ans.denominator]
