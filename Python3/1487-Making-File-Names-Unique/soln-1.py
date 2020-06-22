class Solution:
    def getFolderNames(self, names: List[str]) -> List[str]:
        seen = set()
        nxt = {}
        ans = []
        for name in names:
            if name not in seen:
                ans.append(name)
            else:
                suffix = nxt.get(name, 1)
                while f"{name}({suffix})" in seen:
                    suffix += 1
                ans.append(f"{name}({suffix})")
                nxt[name] = suffix + 1
            seen.add(ans[-1])
        return ans
