class Solution:
    def sumEvenAfterQueries(self, A: 'List[int]', queries: 'List[List[int]]') -> 'List[int]':
        evens = sum(num for num in A if num % 2 == 0)
        ans = []
        for val, idx in queries:
            if A[idx] % 2 == 0:
                A[idx] += val
                if val % 2 == 0:
                    evens += val
                else:
                    evens -= (A[idx] - val)
            else:
                A[idx] += val
                if val % 2 == 1:
                    evens += A[idx]
            ans.append(evens)
        return ans
