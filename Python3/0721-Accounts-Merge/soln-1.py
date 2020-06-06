class Solution:
    
    def accountsMerge(self, accounts):
        """
        :type accounts: List[List[str]]
        :rtype: List[List[str]]
        """
        # build a graph that map email to person
        graph = collections.defaultdict(list)
        for i, account in enumerate(accounts):
            for email in account[1:]:
                graph[email].append(i)
        ans = []
        visited = [0] * len(accounts)
        def dfs(i, emails):
            stack = [email for email in accounts[i][1:]]
            visited[i] = 1
            while stack:
                email = stack.pop()
                emails.add(email)
                for person_id in graph[email]:
                    if not visited[person_id]:
                        visited[person_id] = 1
                        stack.extend([email for email in accounts[person_id][1:]])
        for i, account in enumerate(accounts):
            if not visited[i]:
                emails = set()
                dfs(i, emails)
                ans.append([accounts[i][0]] + sorted(emails))
        return ans