class Solution:
    def movesToStamp(self, stamp, target):
        """
        :type stamp: str
        :type target: str
        :rtype: List[int]
        """
        ns, nt = len(stamp), len(target)
        if nt < ns or stamp[0] != target[0] or stamp[-1] != target[-1]:
            return []
        target = list(target)
        res = []
        count = 0
        visited = [False] * nt
        while count < 10 * nt:
            count += 1
            idx = -1
            for i in range(nt - ns + 1):
                if visited[i]: continue
                num = 0
                for j in range(ns):
                    if '*' != target[i + j] != stamp[j]:
                        break
                    elif target[i + j] != '*':
                        num += 1
                else:
                    if num:
                        idx = i
                        break
            if idx == -1: break
            target[idx: idx + ns] = ['*'] * ns
            visited[idx] = True
            res.append(idx)
        return res[::-1] if all(item == '*' for item in target) else []