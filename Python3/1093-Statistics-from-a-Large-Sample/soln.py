class Solution:
    def sampleStats(self, count: List[int]) -> List[float]:
        # min, max, mean, median, mode
        def kth_element(k):
            """return k-th element"""
            for val, cnt in enumerate(count):
                if k <= cnt:
                    return val
                else:
                    k -= cnt
        mn = -1
        mx = -1
        summation = 0
        n = 0
        mode = -1
        mx_cnt = 0
        for val, cnt in enumerate(count):
            summation += val * cnt
            n += cnt
            if cnt > 0:
                if mn == -1:
                    mn = val
                mx = val
                if cnt > mx_cnt:
                    mx_cnt = cnt
                    mode = val
        mean = summation / n
        median = kth_element(n // 2) if n % 2 else (0.5 * (kth_element(n // 2) + kth_element(n // 2 + 1)))
        return mn, mx, mean, median, mode
        
