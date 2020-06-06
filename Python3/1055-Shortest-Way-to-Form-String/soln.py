class Solution:
    def shortestWay(self, source: str, target: str) -> int:
        chars = set(source)
        if not all(ch in chars for ch in target):
            return -1
        cnt = 0
        idx = 0
        for ch in itertools.cycle(source):
            cnt += 1
            if ch == target[idx]:
                idx += 1
                if idx == len(target):
                    return (cnt + len(source) - 1) // len(source)
