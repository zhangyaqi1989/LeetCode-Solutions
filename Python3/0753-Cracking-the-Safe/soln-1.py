class Solution:
    def crackSafe(self, n: int, k: int) -> str:
        total = k ** n
        path = [0] * n
        seen = {tuple([0] * n)}
        def dfs(path):
            if len(seen) == total:
                return True
            else:
                last = path[-(n - 1):] if n > 1 else []
                for i in range(k):
                    passwd = tuple(last + [i])
                    if passwd not in seen:
                        seen.add(passwd)
                        path.append(i)
                        if not dfs(path):
                            path.pop()
                            seen.remove(passwd)
                        else:
                            return True
                return False
        dfs(path)
        # print(seen)
        return ''.join(map(str, path))
