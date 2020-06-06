class Solution:
    def shortestAlternatingPaths(self, n: int, red_edges: List[List[int]], blue_edges: List[List[int]]) -> List[int]:
        reds = collections.defaultdict(list)
        blues = collections.defaultdict(list)
        for i, j in red_edges:
            reds[i].append(j)
        for i, j in blue_edges:
            blues[i].append(j)
        # print(reds, blues)
        frontier = collections.deque([(v, 'r') for v in reds[0]] + [(v, 'b') for v in blues[0]])
        # print(frontier)
        ans = [-1] * n
        ans[0] = 0
        step = 0
        seen = {(0, 'r'), (0, 'b')}
        for node, c in frontier:
            seen.add((node, c))
        while frontier:
            step += 1
            sz = len(frontier)
            for _ in range(sz):
                node, color = frontier.popleft()
                if ans[node] == -1:
                    ans[node] = step
                nei_lst = blues if color == 'r' else reds
                for nei in nei_lst[node]:
                    new_color = 'r' if color == 'b' else 'b'
                    if (nei, new_color) not in seen:
                        seen.add((nei, new_color))
                        frontier.append((nei, new_color))
        return ans
