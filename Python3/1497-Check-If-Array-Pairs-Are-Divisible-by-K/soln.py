class Solution:
    def canArrange(self, arr: List[int], k: int) -> bool:
        counter = collections.Counter(num % k for num in arr)
        if counter[0] % 2 != 0:
            return False
        for val, cnt in counter.items():
            if val != 0 and counter.get(k - val, 0) != cnt:
                return False
        return True
