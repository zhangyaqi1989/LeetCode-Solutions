ass Solution:
    def minTransfers(self, transactions: List[List[int]]) -> int:
        balances = collections.Counter()
        for x, y, z in transactions:
            balances[x] -= z
            balances[y] += z
        arr = [v for v in balances.values() if v]
        def dfs(arr, idx):
            while idx < len(arr) and arr[idx] == 0:
                idx += 1
            if idx == len(arr):
                return 0
            v = arr[idx]
            arr[idx] = 0
            ans = math.inf
            for i in range(idx + 1, len(arr)):
                if arr[i] * v < 0:
                    arr[i] += v
                    ans = min(ans, 1 + dfs(arr, idx + 1))
                    arr[i] -= v
            arr[idx] = v
            return ans
        return dfs(arr, 0)
