class Solution:
    def addNegabinary(self, arr1: List[int], arr2: List[int]) -> List[int]:
        res = []
        i, j = len(arr1) - 1, len(arr2) - 1
        carry = 0
        while i >= 0 or j >= 0 or carry:
            if i >= 0:
                carry += arr1[i]
                i -= 1
            if j >= 0:
                carry += arr2[j]
                j -= 1
            res.append(carry & 1)
            carry = -(carry >> 1)
        while len(res) > 1 and res[-1] == 0:
            res.pop()
        return res[::-1]
