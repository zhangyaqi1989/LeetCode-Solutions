class Solution:
    def killProcess(self, pid, ppid, kill):
        """
        :type pid: List[int]
        :type ppid: List[int]
        :type kill: int
        :rtype: List[int]
        """
        tree = collections.defaultdict(list)
        for child, parent in zip(pid, ppid):
            tree[parent].append(child)
        res = []
        stack = [kill]
        while stack:
            node = stack.pop()
            res.append(node)
            for nei in tree[node]:
                stack.append(nei)
        return res