class Solution:
    def maxSatisfied(self, customers: List[int], grumpy: List[int], X: int) -> int:
        total = sum(customers)
        cur = 0
        un = 0
        n = len(grumpy)
        for i in range(X):
            cur += (grumpy[i] == 1) * customers[i]
        for i in range(n):
            un += (grumpy[i] == 1) * customers[i]
        mx = cur
        for i in range(X, n):
            cur += (grumpy[i] == 1) * customers[i] - (grumpy[i - X] == 1) * customers[i - X]
            mx = max(mx, cur)
        return total - (un - mx)
