class Solution:
    def calculate(self, s: str) -> int:
        last = None
        ans = 0
        op = ""
        num = ""
        s += '+'
        for ch in s:
            if ch == " ":
                continue
            elif ch.isdigit():
                num += ch
            else:
                if num:
                    num = int(num)
                    if op == '*':
                        ans = ans - last + (last * num)
                        last = last * num
                    elif op == '/':
                        ans -= last
                        sign = 1 if last >= 0 else -1
                        last = sign * (abs(last) // num)
                        ans += last
                    elif op == '-':
                        ans -= num
                        last = -num
                    else:
                        ans += num
                        last = num
                op = ch
                num = ""
        return ans
