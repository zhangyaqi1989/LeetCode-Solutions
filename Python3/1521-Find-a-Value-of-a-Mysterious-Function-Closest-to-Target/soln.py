class Solution:
    def closestToTarget(self, arr: List[int], target: int) -> int:
        s = set()
        ans = 1e9
        for num in arr:
            ns = {num}
            for val in s:
                ns.add(num & val)
            for val in ns:
                ans = min(ans, abs(val - target))
            s = ns
        return ans
