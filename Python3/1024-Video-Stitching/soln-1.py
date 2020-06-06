class Solution:
    def videoStitching(self, clips: List[List[int]], T: int) -> int:
        s, e = 0, T
        clips.sort()
        ans = 0
        i, n = 0, len(clips)
        while s < e:
            cand_e = -1
            while i < n and clips[i][0] <= s:
                if clips[i][1] > cand_e:
                    cand_e = clips[i][1]
                i += 1
            if cand_e == -1:
                return -1
            ans += 1
            s = cand_e
        return ans
