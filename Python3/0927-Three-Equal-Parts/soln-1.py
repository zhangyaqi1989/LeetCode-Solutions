class Solution:
    def threeEqualParts(self, A: List[int]) -> List[int]:
        ones = A.count(1)
        n = len(A)
        if ones == 0:
            return [0, n - 1]
        elif ones % 3 != 0:
            return [-1, -1]
        else:
            ones //= 3
            hi = n - 1
            cnt = 0
            while cnt < ones:
                cnt += A[hi] == 1
                hi -= 1
            right = 0
            for i in range(hi + 1, n):
                right = right * 2 + A[i]
            lo = cnt = 0
            left = 0
            while cnt < ones:
                cnt += A[lo] == 1
                lo += 1
            left = 0
            for i in range(0, lo):
                left = left * 2 + A[i]
            # print(left, lo)
            if left > right:
                return [-1, -1]
            mid = 0
            a, b = 0, 0
            for i in range(lo, hi + 1):
                mid = mid * 2 + A[i]
                if mid == right:
                    b = i + 1
                    break
            else:
                return [-1, -1]
            a = lo - 1
            if left == right:
                return [a, b]
            
            while A[lo] != 1:
                if left == right:
                    a = lo - 1
                    break
                left *= 2
                lo += 1
            else:
                if left == right:
                    return [lo - 1, b]
                else:
                    return [-1, -1]
            return [a, b]
                
