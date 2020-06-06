class Solution:
    def reverseWords(self, lst):
        """
        :type lst: List[str]
        :rtype: void Do not return anything, modify str in-place instead.
        """
        lst.reverse()
        i = 0
        lst.append(' ')
        while i < len(lst):
            j = lst.index(' ', i)
            lst[i : j] = lst[i : j][::-1]
            i = j + 1
        lst.pop()
