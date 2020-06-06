class Solution:
    def threeSumMulti(self, A, target):
        """
        :type A: List[int]
        :type target: int
        :rtype: int
        """
        counter = collections.Counter(A)
        A.sort()
        def count(combo, counter):
            c = collections.Counter(combo)
            ans = 1
            for key, cnt in c.items():
                num = counter[key]
                ans *= math.factorial(num) // math.factorial(cnt) // math.factorial(num - cnt)
            return ans
        ans = 0
        for i in range(len(A) - 2):
            if i > 0 and A[i] == A[i - 1]: continue
            l, r = i + 1, len(A) - 1
            while l < r:
                s = A[i] + A[l] + A[r]
                if s == target:
                    ans += count((A[i], A[l], A[r]), counter)
                    while l < r and A[l] == A[l + 1]:
                        l += 1
                    while l < r and A[r] == A[r - 1]:
                        r -= 1
                    l += 1
                    r -= 1
                elif s < target:
                    l += 1
                else:
                    r -= 1
        return ans % (10**9 + 7)