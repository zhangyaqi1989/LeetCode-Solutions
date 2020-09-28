class Solution:
    def minOperations(self, logs: List[str]) -> int:
        nlevels = 0
        for log in logs:
            i = 0
            while i < len(log) and log[i] == '.':
                i += 1
            if i == 0:
                nlevels += 1
            elif i == 2 and nlevels > 0:
                nlevels -= 1
        return nlevels
