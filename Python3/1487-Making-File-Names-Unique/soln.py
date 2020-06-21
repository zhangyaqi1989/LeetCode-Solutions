class Solution:
    def getFolderNames(self, names: List[str]) -> List[str]:
        used = collections.defaultdict(set)
        nxt = collections.defaultdict(lambda : 1)
        seen = set()
        ans = []
        for name in names:
            if name not in seen:
                used[name].add(0)
                ans.append(name)
            else:
                cand = nxt[name]
                while f"{name}({cand})" in seen:
                    cand += 1
                ans.append(f"{name}({cand})")
                used[name].add(cand)
                nxt[name] = cand + 1
            seen.add(ans[-1])
        return ans
