class Solution:
    def accountsMerge(self, accounts: List[List[str]]) -> List[List[str]]:
        n = len(accounts)
        parents = list(range(n))
        def find(x):
            if parents[x] == x:
                return parents[x]
            else:
                parents[x] = find(parents[x])
                return parents[x]
        def unite(x, y):
            rx, ry = find(x), find(y)
            if rx != ry:
                parents[rx] = ry
        graph = collections.defaultdict(list)
        for idx, account in enumerate(accounts):
            for email in itertools.islice(account, 1, len(account)):
                graph[email].append(idx)
        for email, idxes in graph.items():
            for a, b in zip(idxes, idxes[1:]):
                unite(a, b)
        m = collections.defaultdict(list)
        for x in range(n):
            m[find(x)].append(x)
        ans = []
        for idx, lst in m.items():
            name = accounts[idx][0]
            emails = set()
            for i in lst:
                emails.update(set(accounts[i][1:]))
            ans.append([name] + sorted(emails))
        return ans
        
        
