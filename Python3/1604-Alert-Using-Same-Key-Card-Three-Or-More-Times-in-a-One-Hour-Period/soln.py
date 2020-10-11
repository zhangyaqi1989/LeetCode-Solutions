class Solution:
    def alertNames(self, keyName: List[str], keyTime: List[str]) -> List[str]:
        times = collections.defaultdict(list)
        for name, time in zip(keyName, keyTime):
            h, m = map(int, time.split(':'))
            times[name].append((h, m))
        for lst in times.values():
            lst.sort()
        ans = []
        for name, lst in times.items():
            m = len(lst)
            for i in range(1, m - 1):
                h1, m1 = lst[i - 1]
                h2, m2 = lst[i + 1]
                if h2 * 60 + m2 - (h1 * 60 + m1) <= 60:
                    ans.append(name)
                    break
        ans.sort()
        return ans
