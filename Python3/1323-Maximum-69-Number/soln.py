class Solution:
    def maximum69Number (self, num: int) -> int:
        num_str = list(str(num))
        for i, ch in enumerate(num_str):
            if ch == '6':
                num_str[i] = '9'
                break
        return int(''.join(num_str))
