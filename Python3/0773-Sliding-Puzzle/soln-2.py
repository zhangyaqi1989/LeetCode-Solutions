class Solution:
    def slidingPuzzle(self, board: List[List[int]]) -> int:
        # 0 1 2
        # 3 4 5
        target = '123450'
        start = ''.join(map(str, board[0])) + ''.join(map(str, board[1]))
        start_idx = start.index('0')
        moves = [(1, 3), (0, 2, 4), (1, 5), (0, 4), (1, 3, 5), (2, 4)]
        step = 0
        levels = {start : 0}
        frontier = [(start, start_idx)]
        while frontier:
            nxt_level = []
            for node, idx in frontier:
                if node == target:
                    return levels[node]
                chars = list(node)
                for nei_idx in moves[idx]:
                    chars[idx], chars[nei_idx] = chars[nei_idx], chars[idx]
                    nei = ''.join(chars)
                    chars[idx], chars[nei_idx] = chars[nei_idx], chars[idx]
                    if nei not in levels:
                        levels[nei] = step + 1
                        nxt_level.append((nei, nei_idx))
            frontier = nxt_level
            step += 1
        return -1
