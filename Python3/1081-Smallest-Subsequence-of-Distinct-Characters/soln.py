class Solution:
    def smallestSubsequence(self, text: str) -> str:
        text = tuple(map(ord, text))
        right = {num : i for i, num in enumerate(text)}
        seen = set()
        stack = []
        for i, num in enumerate(text):
            if num not in seen:
                while stack and num < stack[-1] and right[stack[-1]] > i:
                    seen.remove(stack.pop())
                stack.append(num)
                seen.add(num)
        return ''.join(map(chr, stack))
