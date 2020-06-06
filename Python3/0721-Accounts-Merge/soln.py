class Solution:
    def accountsMerge(self, accounts):
        """
        :type accounts: List[List[str]]
        :rtype: List[List[str]]
        """
        visited = [0] * len(accounts)
        graph = collections.defaultdict(list)
        for i, account in enumerate(accounts):
            for j in range(1, len(account)):
                email = account[j]
                graph[email].append(i)
        def dfs(i, emails):
            if visited[i]:
                return
            visited[i] = 1
            for j in range(1, len(accounts[i])):
                email = accounts[i][j]
                emails.add(email)
                for nei in graph[email]:
                    dfs(nei, emails)
        res = []
        for i, account in enumerate(accounts):
            if visited[i]: continue
            name, emails = account[0], set()
            dfs(i, emails)
            print(emails)
            res.append([name] + sorted(emails))
        return res