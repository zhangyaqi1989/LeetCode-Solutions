class Solution:
    def validateStackSequences(self, pushed, popped):
        """
        :type pushed: List[int]
        :type popped: List[int]
        :rtype: bool
        """
        lst = []
        i = 0
        for num in pushed:
            lst.append(num)
            while lst and lst[-1] == popped[i]:
                lst.pop()
                i += 1
        return not lst