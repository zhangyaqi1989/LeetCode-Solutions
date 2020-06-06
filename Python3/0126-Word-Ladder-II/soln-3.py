class Solution:
    def findLadders(self, start: str, target: str, wordList: List[str]) -> List[List[str]]:
        words = set(wordList)
        if target not in words:
            return []
        def neighbor(w):
            n = len(w)
            for i in range(n):
                for ch in string.ascii_lowercase:
                    yield w[:i] + ch + w[i + 1:]
        def path(w, parents):
            if w not in parents:
                return [[w]]
            else:
                return [p + [w] for prev in parents[w]
                                for p in path(prev, parents)]
        def update_level(frontier, level, target_level, i, parents):
            nxt_level = []
            meet = None
            for node in frontier:
                if node in target_level:
                    return nxt_level, node
                for nei in neighbor(node):
                    if nei in words:
                        if nei not in level or level[nei] >= i + 1:
                            level[nei] = i + 1
                            parents[nei].add(node)
                            nxt_level.append(nei)
            return nxt_level, meet
        fparents = collections.defaultdict(set)
        bparents = collections.defaultdict(set)
        n = len(start)
        flevel = {start : 0}
        blevel = {target : 0}
        forward_frontier = [start]
        backward_frontier = [target]
        fi = 0
        bi = 0
        while forward_frontier and backward_frontier:
            if len(forward_frontier) <= len(backward_frontier):
                forward_frontier, meet = update_level(forward_frontier, flevel, blevel, fi, fparents)
                fi += 1
            else:
                backward_frontier, meet = update_level(backward_frontier, blevel, flevel, bi, bparents)
                bi += 1
            if meet is not None:
                paths = []
                for meet in (flevel.keys() & blevel.keys()):
                    fpath = path(meet, fparents)
                    bpath = path(meet, bparents)
                    paths.extend(f + b[::-1][1:] for f in fpath 
                                                 for b in bpath)
                mn = len(min(paths, key=len))
                return [p for p in paths if len(p) == mn]
        return []
