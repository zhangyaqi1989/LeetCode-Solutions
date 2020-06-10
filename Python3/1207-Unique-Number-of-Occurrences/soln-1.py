class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        N = 2005
        counter = [0] * N
        for num in arr:
            counter[num + 1000] += 1
        seen = set()
        for cnt in counter:
            if not cnt:
                continue
            if cnt in seen:
                return False
            seen.add(cnt)
        return True
