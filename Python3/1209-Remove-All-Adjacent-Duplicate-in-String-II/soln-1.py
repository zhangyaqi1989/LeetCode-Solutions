class Solution:
    def removeDuplicates(self, s: str, k: int) -> str:
        stack = []
        for ch, g in itertools.groupby(s):
            cnt = len(list(g)) % k
            if cnt == 0: continue
            if not stack or stack[-1][0] != ch:
                stack.append([ch, cnt])
            else:
                stack[-1][-1] = (stack[-1][-1] + cnt) % k
                if stack[-1][-1] == 0:
                    stack.pop()
        return ''.join(ch * cnt for ch, cnt in stack)
