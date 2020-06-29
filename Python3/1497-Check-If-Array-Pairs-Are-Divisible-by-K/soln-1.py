class Solution:
    def canArrange(self, arr: List[int], k: int) -> bool:
        mods = [0] * k
        for num in arr:
            mods[num % k] += 1
        if mods[0] % 2 != 0:
            return False
        for mod in range(1, k):
            if mods[mod] != 0:
                complement = k - mod
                if mods[complement] != mods[mod]:
                    return False
        return True
