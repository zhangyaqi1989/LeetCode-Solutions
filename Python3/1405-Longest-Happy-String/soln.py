class Solution:
    def longestDiverseString(self, a: int, b: int, c: int) -> str:
        pq = [(-a, 'a'), (-b, 'b'), (-c, 'c')]
        pq = [(cnt, ch) for cnt, ch in pq if cnt != 0]
        heapq.heapify(pq)
        lst = []
        stage_cnt = 0
        stage_ch = 'a'
        while pq:
            cnt, ch = heapq.heappop(pq)
            cnt = -cnt;
            if len(lst) >= 2 and lst[-1] == ch == lst[-2]:
                if not pq:
                    break
                cnt1, ch1 = heapq.heappop(pq)
                cnt1 = -cnt1
                lst.append(ch1)
                cnt1 -= 1
                if cnt1 > 0:
                    heapq.heappush(pq, (-cnt1, ch1))
            else:
                lst.append(ch)
                cnt -= 1
            if cnt > 0:
                heapq.heappush(pq, (-cnt, ch))
            # print(lst)
        return ''.join(lst)
