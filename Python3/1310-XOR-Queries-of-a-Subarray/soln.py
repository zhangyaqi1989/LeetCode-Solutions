class Solution:
    def xorQueries(self, arr: List[int], queries: List[List[int]]) -> List[int]:
        prefixes = [[0] for _ in range(32)]
        for num in arr:
            for i in range(32):
                if (num & (1 << i)):
                    prefixes[i].append(prefixes[i][-1] + 1)
                else:
                    prefixes[i].append(prefixes[i][-1])
        ans = []
        n = len(arr)
        for l, r in queries:
            xor = 0
            for i in range(32):
                cnt = prefixes[i][r + 1] - prefixes[i][l]
                one = cnt % 2
                v = one % 2
                if v == 1:
                    xor |= (1 << i)
            ans.append(xor)
        return ans
