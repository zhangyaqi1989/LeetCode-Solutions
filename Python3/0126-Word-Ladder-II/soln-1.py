class Solution:
    def findLadders(self, beginWord: str, endWord: str, wordList: List[str]) -> List[List[str]]:
        words = set(wordList)
        if endWord not in words:
            return []
        frontier = collections.deque([(beginWord, [beginWord], 0)])
        mn_cost = math.inf
        ans = []
        costs = {beginWord : 0}
        while frontier:
            node, path, cost = frontier.popleft()
            if node == endWord:
                mn_cost = min(mn_cost, cost)
                ans.append(path)
            if cost > mn_cost:
                continue
            else:
                for i in range(len(node)):
                    for ch in string.ascii_lowercase:
                        nei = node[:i] + ch + node[i + 1:]
                        if nei in words and (nei not in costs or costs[nei] >= costs[node] + 1):
                            frontier.append((nei, path + [nei], costs[node] + 1))
                            costs[nei] = costs[node] + 1
        return ans
