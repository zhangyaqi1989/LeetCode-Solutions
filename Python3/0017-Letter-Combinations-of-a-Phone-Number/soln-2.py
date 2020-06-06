class Solution:
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        if not digits:
            return []
        keypad = ['', '', 'abc', 'def', 'ghi', 'jkl',
                  'mno', 'pqrs', 'tuv', 'wxyz']
        return [''.join(combo) 
                for combo in itertools.product(
                *[keypad[ord(digit) - ord('0')] for digit in digits])]