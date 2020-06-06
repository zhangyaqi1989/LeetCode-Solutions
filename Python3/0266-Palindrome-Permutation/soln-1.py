class Solution:
    def canPermutePalindrome(self, s: 'str') -> 'bool':
        pool = set()
        for ch in s:
            if ch in pool:
                pool.remove(ch)
            else:
                pool.add(ch)
        return len(pool) == 0 or len(pool) == 1
