class Solution:
    def buddyStrings(self, A, B):
        """
        :type A: str
        :type B: str
        :rtype: bool
        """
        if len(A) != len(B):
            return False
        swaps = []
        for i, (a, b) in enumerate(zip(A, B)):
            if a != b:
                swaps.append(i)
                if len(swaps) > 2:
                    return False
        return (not swaps and len(A) != len(set(A))) or (len(swaps) == 2 and A[swaps[0]] == B[swaps[1]] and A[swaps[1]] == B[swaps[0]])
