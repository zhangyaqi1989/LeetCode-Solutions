class Solution:
    def addToArrayForm(self, A: 'List[int]', K: 'int') -> 'List[int]':
        A = A[::-1]
        carry = 0
        A[0] += K
        n = len(A)
        for i in range(n):
            temp = A[i] + carry
            carry, A[i] = divmod(temp, 10)
        while carry:
            A.append(carry % 10)
            carry //= 10
        return A[::-1]
