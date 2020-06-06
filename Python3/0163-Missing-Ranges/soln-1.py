class Solution:
    def findMissingRanges(self, nums: List[int], lower: int, upper: int) -> List[str]:
        def tostring(a, b):
            if a == b:
                return str(a)
            else:
                return "{}->{}".format(a, b)
        missing = []
        for num in nums:
            if num == lower:
                lower = num + 1
            elif num > lower:
                missing.append(tostring(lower, num - 1))
                lower = num + 1
        if lower <= upper:
            missing.append(tostring(lower, upper))
        return missing
