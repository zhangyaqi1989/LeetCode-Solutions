class Solution:
    def findLadders(self, beginWord: str, endWord: str, wordList: List[str]) -> List[List[str]]:
        words = set(wordList)
        if endWord not in words:
            return []
        frontier = collections.deque([(beginWord)])
        mn_cost = math.inf
        costs = {w : math.inf for w in words}
        costs[beginWord] = 0
        costs[endWord] = math.inf
        prev = collections.defaultdict(set)
        while frontier:
            sz = len(frontier)
            for _ in range(sz):
                node = frontier.popleft()
                if node == endWord:
                    mn_cost = min(mn_cost, costs[node])
                if costs[node] > mn_cost:
                    continue
                else:
                    for i in range(len(node)):
                        for ch in string.ascii_lowercase:
                            nei = node[:i] + ch + node[i + 1:]
                            if nei in words and costs[nei] >= costs[node] + 1:
                                frontier.append(nei)
                                if costs[nei] > costs[node] + 1:
                                    prev[nei] = {node}
                                else:
                                    prev[nei].add(node)
                                costs[nei] = costs[node] + 1
        ans = []
        def helper(path, target, ans):
            if path[-1] == target:
                ans.append(path[::-1])
            else:
                for nei in prev[path[-1]]:
                    helper(path + [nei], target, ans)
        helper([endWord], beginWord, ans)
        return ans
