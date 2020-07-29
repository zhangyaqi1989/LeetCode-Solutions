class Solution:
    def stringShift(self, s: str, shift: List[List[int]]) -> str:
        left_shift = sum((v if d == 0 else -v) for d, v in shift) % len(s)
        return s[left_shift:] + s[:left_shift]
