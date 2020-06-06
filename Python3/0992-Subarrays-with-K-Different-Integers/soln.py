class Solution:
    def subarraysWithKDistinct(self, A: 'List[int]', K: 'int') -> 'int':
        def helper(k):
            "number of subarrays that has more than k distinct elements."
            counter = collections.Counter()
            j = 0
            ans = 0
            for num in A:
                counter[num] += 1
                while len(counter) >= k:
                    counter[A[j]] -= 1
                    if counter[A[j]] == 0:
                        counter.pop(A[j])
                    j += 1
                ans += j
            return ans
        return helper(K) - helper(K + 1)
