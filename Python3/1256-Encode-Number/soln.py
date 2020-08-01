class Solution:
    def encode(self, num: int) -> str:
        if num == 0:
            return ""
        return self.encode((num - 1) // 2) + "10"[num & 1]
