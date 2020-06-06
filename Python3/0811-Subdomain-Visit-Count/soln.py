class Solution(object):
    def subdomainVisits(self, cpdomains):
        """
        :type cpdomains: List[str]
        :rtype: List[str]
        """
        counter = collections.Counter()
        for item in cpdomains:
            num, url = item.split()
            num = int(num)
            i = 0
            while True:
                counter[url[i:]] += num
                j = url.find('.', i)
                if j == -1:
                    break
                else:
                    i = j + 1
        return ['{} {}'.format(cnt, key) for key, cnt in counter.items()]