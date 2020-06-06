class Solution:
    def addToArrayForm(self, A: 'List[int]', K: 'int') -> 'List[int]':
        ans = 0
        for num in A:
            ans = ans * 10 + num
        ans += K
        return [int(ch) for ch in str(ans)]
