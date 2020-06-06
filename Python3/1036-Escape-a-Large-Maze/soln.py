class Solution:
    def isEscapePossible(self, blocked: List[List[int]], source: List[int], target: List[int]) -> bool:
        nb = len(blocked)
        blocked = {(x, y) for x, y in blocked}
        source = tuple(source)
        target = tuple(target)
        if source in blocked or target in blocked:
            return False
        def helper(start, end):
            n = 1000000
            seen = set()
            seen.add(start)
            queue = collections.deque([start])
            while queue:
                if len(queue) > len(blocked):
                    return 1
                size = len(queue)
                for _ in range(size):
                    node = queue.popleft()
                    if node == end:
                        return 2
                    i, j = node
                    for ni, nj in (i - 1, j), (i + 1, j), (i, j - 1), (i, j + 1):
                        if 0 <= ni < n and 0 <= nj < n and (ni, nj) not in blocked and (ni, nj) not in seen:
                            seen.add((ni, nj))
                            queue.append((ni, nj))
            return 0
        return helper(source, target) + helper(target, source) > 1
