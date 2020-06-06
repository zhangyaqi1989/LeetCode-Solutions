class Solution:
    def isEscapePossible(self, blocked: List[List[int]], source: List[int], target: List[int]) -> bool:
        blocked = {(x, y) for x, y in blocked}
        source = tuple(source)
        target = tuple(target)
        def bfs(s, e):
            visited = {s}
            frontier = collections.deque([s])
            while frontier:
                sz = len(frontier)
                if sz > len(blocked) * 4:
                    return 1
                for i in range(sz):
                    r, c = frontier.popleft()
                    if (r, c) == e:
                        return 2
                    for newr, newc in (r - 1, c), (r + 1, c), (r, c - 1), (r, c + 1):
                        if 0 <= newr < 1000000 and 0 <= newc < 1000000 and (newr, newc) not in blocked and (newr, newc) not in visited:
                            visited.add((newr, newc))
                            frontier.append((newr, newc))
            return 0
        return bfs(source, target) + bfs(target, source) > 1
