class Solution:
    def videoStitching(self, clips: List[List[int]], T: int) -> int:
        clips.sort()
        i = 0
        n = len(clips)
        while i < n:
            if clips[i][1] < 0:
                i += 1
            else:
                break
        cnt = 0
        start = 0
        while start < T:
            best = None
            while i < n and clips[i][0] <= start:
                if best is None or clips[i][1] > best[1]:
                    best = clips[i]
                i += 1
            if best is None:
                return -1
            cnt += 1
            start = best[1]
        return cnt
