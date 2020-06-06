class Solution:
    def removeDuplicateLetters(self, s):
        """
        :type s: str
        :rtype: str
        """
        rindex = {ch : i for i, ch in enumerate(s)}
        stack = []
        inserted = set()
        for i, ch in enumerate(s):
            if ch not in inserted:
                while stack and ch < stack[-1] and i < rindex[stack[-1]]:
                    inserted.remove(stack.pop())
                stack.append(ch)
                inserted.add(ch)
        return ''.join(stack)