class Solution:
    def bitwiseComplement(self, N: int) -> int:
        lst = ['01'[ch == '0'] for ch in bin(N)[2:]]
        return int(''.join(lst), 2)
