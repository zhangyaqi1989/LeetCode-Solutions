class Solution:
    def smallestSubsequence(self, text: str) -> str:
        last = {ch : i for i, ch in enumerate(text)}
        stack = []
        ins = set()
        for i, ch in enumerate(text):
            if ch not in ins:
                while stack and ch < stack[-1] and last[stack[-1]] > i:
                    ins.remove(stack.pop())
                stack.append(ch)
                ins.add(ch)
        return ''.join(stack)
