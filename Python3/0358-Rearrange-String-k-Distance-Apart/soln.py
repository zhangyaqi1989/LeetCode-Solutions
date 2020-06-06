class Solution:
    def rearrangeString(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: str
        """
        pq = [(-fre, ch) for ch, fre in collections.Counter(s).items()]
        heapq.heapify(pq)
        ans = ''
        while len(ans) < len(s):
            fre, ch = heapq.heappop(pq)
            ans += ch
            stack = []
            for _ in range(k - 1):
                if len(ans) == len(s):
                    return ''.join(ans)
                if not pq:
                    return ''
                f, nxt = heapq.heappop(pq)
                if f < -1:
                    stack.append((f + 1, nxt))
                ans += nxt
            for item in stack:
                heapq.heappush(pq, item)
            if fre < -1:
                heapq.heappush(pq, (fre + 1, ch))
        return ''.join(ans)