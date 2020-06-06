class Solution:
    def threeEqualParts(self, A):
        """
        :type A: List[int]
        :rtype: List[int]
        """
        ones = A.count(1)
        one, rem = divmod(ones, 3)
        if rem:
            return [-1, -1]
        l, r = 0, len(A) - 1
        n = len(A)
        cnt = 0
        while l < len(A):
            cnt += A[l] == 1
            if cnt == one:
                break
            l += 1
        cnt = 0
        while r >= 0:
            cnt += A[r] == 1
            if cnt == one:
                break
            r -= 1
        # print(l, r)
        left = int(''.join(map(str, A[:l+1])), 2)
        right = int(''.join(map(str, A[r:])), 2)
        mid = int(''.join(map(str, A[l+1:r])), 2)
        # print(left, mid, right)
        if left > right:
            return [-1, -1]
        while left < right:
            if A[l + 1] == 1:
                return [-1, -1]
            else:
                l += 1
                left *= 2
        if left != right:
            return [-1, -1]
        if mid < right:
            return [-1, -1]
        while mid > right:
                r -= 1
                mid //= 2
                if r == 1:
                    break
        if mid != right:
            return [-1, -1]
        return [l, r]