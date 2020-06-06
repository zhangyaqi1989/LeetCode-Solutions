class Solution:
    def diffWaysToCompute(self, input):
        """
        :type input: str
        :rtype: List[int]
        """
        ops = {'+' : operator.add, '-' : operator.sub, '*' : operator.mul}
        def helper(l, r):
            if input[l:r].isdigit():
                return [int(input[l:r])]
            ans = []
            for i, ch in enumerate(input[l:r], l):
                if ch in '+-*':
                    for left, right in itertools.product(helper(l, i), helper(i + 1, r)):
                        ans.append(ops[ch](left, right))
            return ans
        return helper(0, len(input))