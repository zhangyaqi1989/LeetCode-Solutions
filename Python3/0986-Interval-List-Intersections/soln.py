# Definition for an interval.
# class Interval:
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

class Solution:
    def intervalIntersection(self, A: 'List[Interval]', B: 'List[Interval]') -> 'List[Interval]':
        ans = []
        i, n = 0, len(A)
        for interval in B:
            sb, eb = interval.start, interval.end
            while i < n:
                if A[i].start > eb:
                    break
                elif sb > A[i].end:
                    i += 1
                else:
                    ans.append(Interval(max(sb, A[i].start), min(eb, A[i].end)))
                    if eb >= A[i].end:
                        i += 1
                    else:
                        break
        return ans
