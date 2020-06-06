class Solution:
    def reorganizeString(self, S):
        """
        :type S: str
        :rtype: str
        """
        # how to keep the top 2 most common chars
        res = ''
        counter = collections.Counter(S)
        heap = [(-cnt, ch) for ch, cnt in counter.items()]
        heapq.heapify(heap)
        pre_ch, pre_cnt = '', 0
        while heap:
            cnt, ch = heapq.heappop(heap)
            res += ch
            cnt += 1
            if pre_cnt < 0:
                heapq.heappush(heap, (pre_cnt, pre_ch))
            pre_ch, pre_cnt = ch, cnt
        return res if len(res) == len(S) else ''