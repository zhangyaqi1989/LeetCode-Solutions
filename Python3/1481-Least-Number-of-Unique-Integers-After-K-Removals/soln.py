class Solution:
    def findLeastNumOfUniqueInts(self, arr: List[int], k: int) -> int:
        counter = collections.Counter(arr)
        nremoves = 0
        for _, cnt in reversed(counter.most_common()):
            if k >= cnt:
                k -= cnt
                nremoves += 1
            else:
                break
        return len(counter) - nremoves
