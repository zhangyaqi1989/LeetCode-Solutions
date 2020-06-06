class Solution:
    def ipToCIDR(self, ip, n):
        """
        :type ip: str
        :type n: int
        :rtype: List[str]
        """
        def iptoint(ip):
            nums = list(map(int, ip.split('.')))
            return sum(num << (32 - (i + 1) * 8) for i, num in enumerate(nums))
        def inttoip(num):
            s = '{:032b}'.format(num)
            iters = [iter(s)] * 8
            lst = [int(''.join(sub), 2) for sub in zip(*iters)]
            return '.'.join(map(str, lst))
        def lowbit(num):
            low = 0
            while num & (1 << low) == 0:
                low += 1
            return low
        ans = []
        count = n
        num = iptoint(ip)
        while count > 0:
            low = lowbit(num)
            cnt = 2 ** low # maximum possible cnt
            left = (32 - low) if count >= cnt else (32 - int(math.log2(count)))
            cnt = 2 ** (32 - left)
            ans.append('{}/{}'.format(inttoip(num), left))
            count -= cnt
            num += cnt
        return ans