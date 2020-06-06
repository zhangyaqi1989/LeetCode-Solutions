class Solution:
    def multiply(self, num1, num2):
        """
        :type num1: str
        :type num2: str
        :rtype: str
        """
        # 123
        # 456
        product = [0] * (len(num1) + len(num2))
        pos = len(product) - 1
        zero = ord('0')
        for n1 in reversed(num1):
            cur_pos = pos
            for n2 in reversed(num2):
                v1, v2 = ord(n1) - zero, ord(n2) - zero
                val = v1 * v2
                product[cur_pos] += val
                product[cur_pos - 1] += product[cur_pos] // 10
                product[cur_pos] %= 10
                cur_pos -= 1
            pos -= 1
        ans = ''.join(map(str, product)).lstrip('0')
        return '0' if not ans else ans