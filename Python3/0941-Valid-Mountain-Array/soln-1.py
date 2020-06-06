class Solution:
    def validMountainArray(self, A):
        """
        :type A: List[int]
        :rtype: bool
        """
        increase = None
        for a, b in zip(A, A[1:]):
            if b > a:
                if increase is None:
                    increase = True
                if increase == False:
                    return False
            elif b < a:
                if increase is None:
                    return False
                if increase == True:
                    increase = False
            else:
                return False
        return increase == False