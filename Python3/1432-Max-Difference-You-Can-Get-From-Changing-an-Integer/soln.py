class Solution:
    def maxDiff(self, num: int) -> int:
        digits = [int(ch) for ch in str(num)]
        first = digits[0]
        if first != 9:
            mx_ds = [9 if d == first else d for d in digits]
            mx = int(''.join(map(str, mx_ds)))
        else:
            idx = -1
            for i in range(1, len(digits)):
                if digits[i] != 9:
                    idx = i
                    break
            else:
                mx = num
            if idx != -1:
                mx_ds = [9 if d == digits[idx] else d for d in digits]
                mx = int(''.join(map(str, mx_ds)))
        if first > 1:
            mn_ds = [1 if d == first else d for d in digits]
            mn = int(''.join(map(str, mn_ds)))
        else:
            # == 1, check the first value that is different from first
            idx = -1
            for i in range(1, len(digits)):
                if digits[i] == 0:
                    continue
                if digits[i] != first:
                    idx = i
                    break
            else:
                mn = num
            if idx != -1:
                mn_ds = [0 if d == digits[idx] else d for d in digits]
                mn = int(''.join(map(str, mn_ds)))
        # print(mx, mn)
        return mx - mn
