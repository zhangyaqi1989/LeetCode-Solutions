class Solution:
    def missingElement(self, nums: List[int], k: int) -> int:
        accs = [0]
        n = len(nums)
        for i in range(n - 1):
            accs.append(nums[i + 1] - nums[i] - 1 + accs[-1])
        lo, hi = nums[0] + 1, 1 << 30
        s = set(nums)
        def count(mid):
            idx = bisect.bisect_left(nums, mid)
            cnt = accs[idx - 1]
            ans = cnt + mid - nums[idx - 1]
            return ans - (mid in s)
        while lo <= hi:
            mid = (lo + hi) >> 1
            c = count(mid)
            if c == k:
                for j in range(mid, lo - 1, -1):
                    if j not in s:
                        return j
            elif c > k:
                hi = mid - 1
            else:
                lo = mid + 1
        
