class Solution:
    def removeInvalidParentheses(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        # this is a BFS
        def isValid(s):
            cnt = 0
            for ch in s:
                if ch == '(':
                    cnt += 1
                elif ch == ')':
                    cnt -= 1
                    if cnt < 0:
                        return False
            return cnt == 0
        visited = {s}
        queue = collections.deque([s])
        ans = []
        found = False
        while queue:
            node = queue.popleft()
            if isValid(node):
                ans.append(node)
                found = True
            if found:
                continue
            for i, ch in enumerate(node):
                if ch in '()':
                    nei = node[:i] + node[i + 1:]
                    if nei not in visited:
                        visited.add(nei)
                        queue.append(nei)
        return ans