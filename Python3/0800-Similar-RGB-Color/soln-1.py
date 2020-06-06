class Solution:
    def similarRGB(self, color: str) -> str:
        digits = "0123456789abcdef"
        def helper(sub):
            num = int(sub, 16)
            return min(digits, key=lambda d : abs(int(d * 2, 16) - num)) * 2
        return "#" + helper(color[1:3]) + helper(color[3:5]) + helper(color[5:])
