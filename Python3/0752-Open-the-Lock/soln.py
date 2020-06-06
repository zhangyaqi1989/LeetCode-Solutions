class Solution(object):
    def openLock(self, deadends, target):
        """
        :type deadends: List[str]
        :type target: str
        :rtype: int
        """
        deadends = set(deadends)
        start = '0000'
        if start in deadends or target in deadends:
            return -1
        visited = {start, target}
        s1, s2 = {start}, {target}
        circle = list('0123456789')
        step = 0
        def neighbor(ch):
            idx = int(ch)
            return [circle[idx - 1], circle[(idx + 1) % 10]]
        while s1 and s2:
            if len(s2) < len(s1):
                s1, s2 = s2, s1
            step += 1
            s = set()
            for code in s1:
                for i, ch in enumerate(code):
                    for new_ch in neighbor(ch):
                        new_code = code[:i] + new_ch + code[i + 1:]
                        if new_code in s2:
                            return step
                        if new_code not in deadends and new_code not in visited:
                            visited.add(new_code)
                            s.add(new_code)
            s1 = s
        return -1