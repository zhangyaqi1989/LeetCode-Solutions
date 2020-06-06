class Solution:
    def rearrangeString(self, s: str, k: int) -> str:
        # greedy method
        lefts = [(-freq, ch) for ch, freq in collections.Counter(s).items()]
        heapq.heapify(lefts)
        ans = []
        while len(ans) < len(s):
            if not lefts:
                return ""
            freq, ch = heapq.heappop(lefts)
            ans.append(ch)
            level = [(freq, ch)]
            for j in range(k - 1):
                if len(ans) == len(s):
                    return ''.join(ans)
                if not lefts:
                    return ''
                f, c = heapq.heappop(lefts)
                ans.append(c)
                level.append((f, c))
            for f, c in level:
                if f < -1:
                    heapq.heappush(lefts, (f + 1, c))
        return ''.join(ans)
