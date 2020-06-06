class Solution:
    def validMountainArray(self, A: List[int]) -> bool:
        if len(A) < 3:
            return False
        inc = True
        for i in range(len(A) - 1):
            if A[i] < A[i + 1]:
                if not inc:
                    return False
            elif A[i] > A[i + 1]:
                if inc:
                    inc = False
            else:
                return False
        return inc == False and A[1] > A[0]
