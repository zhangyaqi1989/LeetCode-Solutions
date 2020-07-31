class Solution:
    def countElements(self, arr: List[int]) -> int:
        counter = collections.Counter(arr)
        ans = 0
        for num, cnt in counter.items():
            if (num + 1) in counter:
                ans += cnt
        return ans
