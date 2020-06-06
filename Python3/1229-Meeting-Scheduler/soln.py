class Solution:
    def minAvailableDuration(self, slots1: List[List[int]], slots2: List[List[int]], duration: int) -> List[int]:
        # intersection
        slots1.sort()
        slots2.sort()
        n1, n2 = len(slots1), len(slots2)
        i = 0
        j = 0
        for i in range(n1):
            while j < n2 and slots2[j][1] < slots1[i][0]:
                j += 1
            while j < n2 and slots2[j][0] <= slots1[i][1]:
                s = max(slots1[i][0], slots2[j][0])
                e = min(slots1[i][1], slots2[j][1])
                if e - s >= duration:
                    return [s, s + duration]
                j += 1
            if j > 0:
                j -= 1
        return []
